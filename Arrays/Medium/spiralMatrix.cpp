#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

void printLtoR(vector<vector<int>>& matrix, int &left, int &right, int &top){
    for (int i=left; i<=right; i++){
        answer.push_back(matrix[top][i]);
    }
    top++;
    return;
}

void printRtoL(vector<vector<int>>& matrix, int &right, int &left, int&bottom){
    for (int i=right; i>=left; i--){
        answer.push_back(matrix[bottom][i]);
    }
    bottom--;
    return;
}

void printTtoB(vector<vector<int>>& matrix, int &top, int &bottom, int &right){
    for (int i=top; i<=bottom; i++){
        answer.push_back(matrix[i][right]);
    }
    right--;
    return;
}

void printBtoT(vector<vector<int>>& matrix, int &bottom, int &top, int &left){
    for (int i=bottom; i>=top; i--){
        answer.push_back(matrix[i][left]);
    }
    left++;
    return;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    int left=0, right=nCols-1, top=0, bottom=nRows-1;

    while(left<=right && top<=bottom){
        printLtoR(matrix, left, right, top);
        if (top>bottom) break;
        printTtoB(matrix, top, bottom, right);
        if (left>right) break;
        printRtoL(matrix, right, left, bottom);
        if (top>bottom) break;
        printBtoT(matrix, bottom, top, left);
        if (left>right) break;
    }

    return answer;

}

int main(){

    int n; cin>>n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> spiralMatrix = spiralOrder(matrix);

    cout<<"The matrix printed in spiral manner is: \n";
    for (auto it: spiralMatrix){
        cout<<it<<" ";
    }

    return 0;
}