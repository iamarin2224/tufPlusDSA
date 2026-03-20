#include <iostream>
#include <unordered_set>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList) {
    //Queue to store {string, level}
    queue<pair<string, int>> q;   
    
    unordered_set<string> st(wordList.begin(), wordList.end()); //Set for quick lookup

    if (st.find(targetWord) == st.end()) return 0;

    q.push({startWord, 1});
    st.erase(startWord);

    while (!q.empty()){
        string word = q.front().first;
        int level = q.front().second;

        q.pop();

        if (word == targetWord) return level;

        //See if every word changed with every alphabet results in a word in wordlist, if exist then add to traversal
        for (int i=0; i<word.size(); i++){
            char org = word[i];

            for (char c = 'a'; c <= 'z'; c++){
                word[i] = c;

                if (st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, level+1});
                }
            }

            word[i] = org;
        }
    }

    return 0;
}