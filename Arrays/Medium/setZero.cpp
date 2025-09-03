#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> rowZero(0);
    vector<int> colZero(0);

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (matrix[i][j] == 0){
                rowZero.push_back(i);
                colZero.push_back(j);
            } 
        }
    }

    for (int row: rowZero){
        for (int j=0; j<n; j++){
            matrix[row][j] = 0;
        }
    }

    for (int col: colZero){
        for (int i=0; i<m; i++){
            matrix[i][col] = 0;
        }
    }
}

int main(){

    int m,n; 
    cin>>m; cin>>n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    cout<<"The modified matrix is: \n";
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<<matrix[i][j]<<" "; 
        }
        cout<<endl;
    }

    return 0;
}