#include <iostream>
#include <unordered_set>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord,vector<string> &wordList) {
    vector<vector<string>> ans;
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;

    q.push({beginWord});
    st.erase(beginWord);

    //As we will be deleting elements level wise, this keep track of words to be deleted
    unordered_set<string> toErase;
    
    while (!q.empty()){
        int k = q.size();

        //Traverse level wise
        for (int i=0; i<k; i++){
            vector<string> curList = q.front();
            string word = curList.back();
            q.pop();

            //Add to ans if size equal to shortest transformation
            if (word == endWord){
                if (ans.size() == 0){
                    ans.push_back(curList);
                }
                else if (ans[0].size() == curList.size()){
                    ans.push_back(curList);
                }
            }

            //Similar to prev
            for (int pos = 0; pos < word.size(); pos++){
                char org = word[pos];

                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[pos] = ch;

                    if (st.find(word) != st.end()){
                        curList.push_back(word);
                        q.push(curList);
                        toErase.insert(word);
                        curList.pop_back(); 
                        //Popback is necessary as will help for next paths in next traversals, we pushed to curList to only have that in the queue
                    }

                }

                word[pos] = org;
            }
        }

        //Erase the words (mark them visited) after level traversal 
        for (auto it : toErase) st.erase(it);
        toErase.clear();

        //Exit if ans is found, as in the next level the sequences will not be shortest
        if (!ans.empty()) break;
    }

    return ans;
}