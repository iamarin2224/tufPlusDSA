#include <iostream>
using namespace std;

bool isPalindrome(const string &s, int start, int end){
    if (start>=end) return true;
    if (!isalnum(s[start])) {
        return isPalindrome(s, start+1, end);
    }
    if (!isalnum(s[end])) {
        return isPalindrome(s, start, end-1);
    }
    if (tolower(s[start]) != tolower(s[end])){
        return false;
    }
    return isPalindrome(s, start+1, end-1);
}

int main(){
    string sample;
    cin>>sample;
    if (isPalindrome(sample, 0, sample.size()-1)){
        cout<<"Yes, the given string is a palindrome.";
    }
    else{
        cout<<"No, the given string is not a palindrome.";
    }
    return 0;
}