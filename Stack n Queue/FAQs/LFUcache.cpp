#include <iostream>
using namespace std;

class Node {
    public:
    int key, val, cnt; //cnt -> frequency
    Node* next;
    Node* prev;

    Node(){
        key = -1;
        val = -1;
        cnt = -1;
        next = nullptr;
        prev = nullptr;
    }

    Node(int k, int v){
        key = k;
        val = v;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class List {
    public:
    Node* head;
    Node* tail;

    int size; //for indicating whether list empty

    List(){
        head = new Node();
        tail = new Node();
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    void insertNodeFront(Node* node){
        Node* nextNode = head->next;

        head->next = node;
        node->next = nextNode;
        node->prev = head;
        nextNode->prev = node;

        size++;
    }

    void deleteNode(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyNode; 
    unordered_map<int, List*> freqListMap;  //stores the list for each freq

    int cacheSize;
    int minFreq;
    int curSize;

    //used when updating existing node's position
    void updateFreqMap(Node* node){
        //remove from hashmaps
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);

        //if lastnode of minfreq, update minfreq
        if (node->cnt == minFreq && freqListMap[minFreq]->size == 0){
            minFreq++;
        }

        //new frequency list making, or linking to existing
        List* nextFreqList = new List();

        if (freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextFreqList = freqListMap[node->cnt+1];
        }

        //incrementing the count and adding to new freq list
        node->cnt++;
        nextFreqList->insertNodeFront(node);

        //updating the hashmaps
        freqListMap[node->cnt] = nextFreqList;
        keyNode[node->key] = node;
    }

    public:
    LFUCache(int capacity)  {
        cacheSize = capacity;
        minFreq = 0;
        curSize = 0;

        freqListMap.clear();
        keyNode.clear();
    }

    //get the key and update the fr map
    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;

        Node* node = keyNode[key];

        updateFreqMap(node);

        return node->val;
    }

    void put(int key, int value) {
        //if node exists, modify its value and update position in fr map
        if (keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;

            updateFreqMap(node);

            return;
        }

        //delete the lfu is max size
        if (curSize == cacheSize){
            Node* node = freqListMap[minFreq]->tail->prev;

            keyNode.erase(node->key);
            freqListMap[minFreq]->deleteNode(node);

            curSize--;
        }

        curSize++;
        minFreq = 1;

        //form a list, if it exists point it to existing
        List* newList = new List();
        if (freqListMap.find(minFreq) != freqListMap.end()){
            newList = freqListMap[minFreq];
        }

        Node* node = new Node(key, value);

        //add to the list
        newList->insertNodeFront(node);

        //update the maps
        keyNode[key] = node;
        freqListMap[minFreq] = newList;
    }
};
