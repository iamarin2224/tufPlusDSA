#include <iostream>
using namespace std;

int sof(int n){
  if (n==0) return 0;
  return n + sof(n-1);
}

int main() 
{
    int n; cin>>n;
    cout<<sof(n);
    return 0;
}