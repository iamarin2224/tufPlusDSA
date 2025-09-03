#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n){
    int digits = 0;
    if (n==0) return 1;
    while(n!=0){
        digits++;
        n/=10;
    }
    return digits;
}

int isArmstrong(int n){
    double a_sum = 0;
    int digits = countDigits(n), lastDigit;
    int nCopy = n;
    while(nCopy!=0){
        lastDigit = nCopy%10;
        a_sum += pow((double)lastDigit, (double)digits);
        nCopy/=10;
    }
    a_sum = (int)a_sum;
    return (a_sum==n);
}

int main(){
    int n; 
    cin >> n;
    cout<<isArmstrong(n);
    return 0;
}