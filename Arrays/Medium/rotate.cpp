#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for (int i=0; i<=n-2; i++){
        for (int j=i+1; j<=n-1; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i=0; i<=n-1; i++){
        for (int j=0; j<=(n/2-1); j++){
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
}

int main(){

    int n; cin>>n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

    cout<<"The rotated matrix is: \n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<matrix[i][j]<<" "; 
        }
        cout<<endl;
    }

    return 0;
}