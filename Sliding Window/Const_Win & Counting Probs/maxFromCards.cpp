#include <iostream>
using namespace std;

//? First approach deprecated as, like we can't be sure whether taking the element based on cur left or right will be correct or not. Because if the current left is very small but the element just next to it might be very big
/*
int maxScore(vector<int>& cardScore , int k){
    int n = cardScore.size();
    
    int score = 0;
    int count = 0;
    
    int first = 0, last = n-1;
    
    while (count < k){
        if (cardScore[first] >= cardScore[last]){
            score += cardScore[first];
            first++;
            count++;
        }
        else{
            score += cardScore[last];
            last--;
            count++;
        }
    }
    
    return score;
}
*/

//? Correct approach is to first get the sum of first k, then start by removing one from start and adding from last while maintaining a max
int maxScore(vector<int>& cardScore , int k){
    int n = cardScore.size();

    int prefix = 0;
    for (int i=0; i<=k-1; i++){
        prefix += cardScore[i];
    }

    int curSum = prefix;

    int maxSum = curSum;

    for (int i=0; i<k; i++){
        curSum = curSum - cardScore[k-i-1] + cardScore[n-i-1];
        maxSum = max(maxSum, curSum);
    }

    return maxSum;
}