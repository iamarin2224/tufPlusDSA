#include <iostream>
using namespace std;

int main(){
    
    int n1, n2;
    cin >> n1 >> n2;

    int small, large;
    if (n1>n2){
        small = n2;
        large = n1;
    }
    else{
        small = n1;
        large = n2;
    }

    int i, lcm, prod;
    for (i=1;i<=small;i++){
        prod = large * i;
        if (prod%small==0){
            lcm = prod;
            break;
        }
    }

    cout << "The lcm of "<<n1<<" and "<<n2<<" is: "<<lcm<<endl;

    return 0;
}