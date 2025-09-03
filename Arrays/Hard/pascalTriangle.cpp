#include <bits/stdc++.h> 
using namespace std;

long long nCr(int n, int r){

    if (r>n) return -1;

    else if (r==0 || r==n){
        return 1;
    }

    else if (r==1 || r==n-1){
        return n;
    }

    else{

        //? Naive Approach   

        // long long numr = 1;
        // for (int i=0; i<r; i++){
        //     numr *= n-i;
        // }
        // long long denr = 1;
        // for (int i=2; i<=r; i++){
        //     denr *= i;
        // }

        // return (numr/denr);

        //? Better Approach (Single Loop)

        long long res = 1;
        for (int i=0; i<r; i++){
            res = res * (n-i);
            res = res / i+1;
        }

        return res;
    }
}

vector<int> nthRow(int n){

    //? Naive Approach
    // vector<int> row;

    // for (int i=0; i<=n; i++){
    //     long long value = nCr(n, i);
    //     row.push_back((int)value);
    // }

    // return row;

    //? Optimal Approach --> This doesn't uses the nCr formula, rather uses nCr = nC(r-1) * ((n-r+1)/r)

    vector<int> row;

    long long value = 1;
    row.push_back(1); //nC0 = 1

    for (int i=1; i<=n; i++){
        value = value * (n-i+1) / i;
        row.push_back((int)value);
    }

    return row;

}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer;

    for (int i=0; i<numRows; i++){
        vector<int> row = nthRow(i);
        answer.push_back(row);
    }

    return answer;
}

int main(){

    int n; 
    cin>>n;

    vector<vector<int>> answer = generate(n);

    for (vector<int> row: answer){
        for(int element: row){
            cout<<element<<" ";
        }
        cout<<endl;
    }

    return 0;
}