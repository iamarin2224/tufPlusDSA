#include <iostream>
using namespace std;

class Node {
    public:
    int key, val;
    Node* next;
    Node* prev;

    Node(){
        key = -1;
        val = -1;
        next = nullptr;
        prev = nullptr;
    }

    Node(int k, int v){
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    //hash map to store key-node pair
    unordered_map<int, Node*> mpp;

    //dummy nodes for head and tail
    Node* head;
    Node* tail;

    int cacheSize;

    //insert always next to head, so that recent lies next to
    void insertNodeFront(Node* node){
        Node* nextNode = head->next;

        head->next = node;
        node->next = nextNode;
        node->prev = head;
        nextNode->prev = node;
    }

    void deleteNode(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    public:

    LRUCache(int capacity) {
        cacheSize = capacity;
        mpp.clear(); //clean the existing map

        //declare dummy nodes
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key_) {
        if (mpp.find(key_) == mpp.end()) return -1;

        Node* node = mpp[key_];

        //modify its position in list by deleting existing and inserting fresh
        deleteNode(node);
        insertNodeFront(node);

        return node->val;
    }

    void put(int key_, int value) {
        //if key exist, just modify the value
        if (mpp.find(key_) != mpp.end()) {
            Node* node = mpp[key_];
            node->val = value;

            //modifying its postion
            deleteNode(node);
            insertNodeFront(node);

            return;
        }

        //if full, delete the least recently -> from prev of tail
        if (mpp.size() == cacheSize){
            Node* node = tail->prev;

            mpp.erase(node->key);
            deleteNode(node);
        }

        Node* node = new Node(key_, value);

        //insert the node in map and list
        mpp[key_] = node;
        insertNodeFront(node);
    }
};