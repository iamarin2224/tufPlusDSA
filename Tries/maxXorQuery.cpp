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

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());

    vector<int> ans(queries.size(), -1);

    //store as mi-xi-index
    vector<pair<int, pair<int, int>>> offlineQueries;

    int index = 0;

    for (auto& it: queries){
        offlineQueries.push_back({it[1], {it[0], index++}});
    }

    sort(offlineQueries.begin(), offlineQueries.end());

    int i = 0;
    int n = nums.size();

    Trie t;

    for (auto& it: offlineQueries){
        int xi = it.second.first;
        int mi = it.first;

        while (i<n && nums[i]<=mi){
            t.insert(nums[i]);
        }

        if (i != 0) ans[it.second.second] = t.getMax(xi);
    }

    return ans;
}