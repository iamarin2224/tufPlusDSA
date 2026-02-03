#include <iostream>
using namespace std;

//Brute
int celebrity(vector<vector<int>> &M) {
    int n = M.size();

    //mark all as celeb
    vector<int> celebArr(n, 1);

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            //person i knows other people
            if (M[i][j] == 1) {
                celebArr[i] = 0;
            }
            //perseon j is not known by i
            if (i!=j && M[i][j] == 0){
                celebArr[j] = 0;
            }
        }
    }

    for (int i=0; i<n; i++){
        if (celebArr[i] == 1) return i;
    }

    return -1;
}

//Optimal using 2 pointers
int celebrity(vector<vector<int>> &M) {
    int n = M.size();

    //two pointers on the n persons
    int left=0, right=n-1;

    while (left < right) {
        //left knows right, so left can't be celeb
        if (M[left][right] == 1){
            left++;
        }
        //right knows left, so right can't be celeb
        else if (M[right][left] == 1){
            right--;
        }
        //if both doesn't know each other, both can't be celeb
        else{
            left++, right--;
        }
    }

    //if no convergence, no celebrity
    if (left > right) return -1; 
    
    //check if the one finally pointed to is celebrity 
    for (int i=0; i<n; i++){
        if (i==left) continue;

        if (M[left][i]==1 || M[i][left]==0){
            return -1;
        }
    }

    return left;
}