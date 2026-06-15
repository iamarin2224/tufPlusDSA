#include <iostream>
using namespace std;

struct Node {
    Node* links[26] = {nullptr};
    int eW = 0, cP = 0;

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    Node* get(char ch) { return links[ch - 'a']; }

    void incEndsWith() { eW++; }

    void incPrefix() { cP++; }

    void deleteEnd() { eW--; }

    void reducePrefix() { cP++; }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch: word){
            if (!node->containsKey(ch)){
                node->put(ch, new Node());
            }

            node = node->get(ch);
            node->incPrefix();
        }

        node->incEndsWith();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;

        for (char ch: word){
            if (!node->containsKey(ch)){
                return 0;
            }

            node = node->get(ch);
        }

        return node->eW;
    }

    int countWordsStartingWith(string word) {
        Node* node = root;

        for (char ch: word){
            if (!node->containsKey(ch)){
                return 0;
            }

            node = node->get(ch);
        }

        return node->cP;
    }

    void erase(string word) {
        if (countWordsEqualTo(word) == 0) return;

        Node* node = root;

        for (char ch: word){
            if (!node->containsKey(ch)){
                return;
            }

            node = node->get(ch);
            node->reducePrefix();
        }

        node->deleteEnd();
    }
};
