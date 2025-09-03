#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int col0 = 1;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (matrix[i][j] == 0){
                matrix[i][0] = 0;   //using row 1 as rowZero array
                if (j!=0) matrix[0][j] = 0; //using col 1 as colZero array
                else col0 = 0;  //cause else we will be marking (0,0) twice
            } 
        }
    }

    for (int i=1; i<m; i++){
        for (int j=1; j<n; j++){
            if (matrix[i][j] != 0){
                if (matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0){
        for (int j=0; j<n; j++){
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0){
        for (int i=0; i<m; i++){
            matrix[i][0] = 0;
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