#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b){
    int pA=0, pB=0;
    vector<int> answer;

    while (pA<a.size() && pB<b.size()){

        while (pA+1<a.size() && a[pA]==a[pA+1]) pA++; 
        while (pB+1<b.size() && b[pB]==b[pB+1]) pB++; 

        if (pA >= a.size() || pB >= b.size()) break;

        if (a[pA]<b[pB]){
            answer.push_back(a[pA]);
            pA++;
        }
        else if (a[pA]>b[pB]){
            answer.push_back(b[pB]);
            pB++;
        }
        else if (a[pA]==b[pB]){
            answer.push_back(a[pA]);
            pA++; pB++;
        }
    }

    while (pA<a.size()){
        while (pA+1<a.size() && a[pA]==a[pA+1]) pA++;
        if (pA >= a.size()) break;
        answer.push_back(a[pA]);
        pA++;
    }

    while (pB<b.size()){
        while (pB+1<b.size() && b[pB]==b[pB+1]) pB++;
        if (pB >= b.size()) break;
        answer.push_back(b[pB]);
        pB++;
    }

    return answer;
}

int main(){

    int n1; cin>>n1;
    vector<int> a(n1);
    for (int i=0; i<n1; i++){
        cin>>a[i];
    }
    int n2; cin>>n2;
    vector<int> b(n2);
    for (int i=0; i<n2; i++){
        cin>>b[i];
    }
    
    vector<int> unionVec = findUnion(a, b);

    cout<<"The vector after union is: "<<endl;
    for (int i=0; i<unionVec.size(); i++){
        cout<<unionVec[i]<<" ";
    }

    return 0;
}