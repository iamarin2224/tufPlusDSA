#include <iostream>
using namespace std;

int hcf (int a, int b){
    while(a>0 && b>0){
        if (a>b) a = a%b;
        else b = b%a;
    }
    if (a==0) return b;
    else return a;
}

int main(){
    int n1, n2; 
    cin>>n1; cin>>n2;
    cout<<"HCF of "<<n1<<" and "<<n2<<" is: "<<hcf(n1, n2)<<endl;
    return 0;
}