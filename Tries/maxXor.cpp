#include <iostream>
using namespace std;

struct Node {
    Node* links[2] = {nullptr};
    bool flag = false;

    bool containsKey(int bit) { return links[bit] != nullptr; }

    void put(int bit, Node* node) { links[bit] = node; }

    Node* get(int bit) { return links[bit]; }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i=31; i>=0; i--){
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)){
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;

        int maxNum = 0;

        for (int i=31; i>=0; i--){
            int bit = (num >> i) & 1;

            if (node->containsKey(1-bit)){
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie t;

    for (int i=0; i<nums.size(); i++){
        t.insert(nums[i]);
    }

    int ans = 0;
    for (int i=0; i<nums.size(); i++){
        ans = max(ans, t.getMax(nums[i]));
    }

    return ans;
}