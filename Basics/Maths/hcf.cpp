#include <iostream>
using namespace std;

int main(){

    int n1, n2;
    cin >> n1 >> n2;

    int s;
    if (n1>n2) s = n2;
    else s = n1;

    int i, hcf;
    for (i=1; i<=s; i++){
        if (n1%i==0 && n2%i==0){
            hcf = i;
        }
    }

    cout << "The hcf of "<<n1<<" and "<<n2<<" is: "<<hcf<<endl;

    return 0;
}