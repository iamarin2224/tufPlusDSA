#include <iostream>
using namespace std;

struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    Node* get(char ch) { return links[ch - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch: word){
            if (!node->containsKey(ch)){
                node->put(ch, new Node());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool checkAllPrefixExist(string word){
        Node* node = root;

        for (int i=0; i<word.size(); i++){
            if (node->containsKey(word[i])){
                node = node->get(word[i]);
                if (!node->isEnd()){
                    return false;
                }
            }
            else{
                return false;
            }
        }

        return true;
    }
};

string completeString(vector<string>& nums) {
    Trie t;
    
    for (int i=0; i<nums.size(); i++){
        t.insert(nums[i]);
    }

    string ans = "";

    for (int i=0; i<nums.size(); i++){
        if (t.checkAllPrefixExist(nums[i])){
            if ((nums[i].size() > ans.size()) || 
                (nums[i].size() == ans.size() && nums[i] < ans)
            ){
                ans = nums[i];
            }
        }
    }

    return ans == "" ? "None" : ans;
}