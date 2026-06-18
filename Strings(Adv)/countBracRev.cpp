#include <iostream>
using namespace std;

int countRev (string s) {
    if (s.size()%2 == 1) return -1;

    int opening = 0, closing = 0;

    for (char ch: s){
        if (ch == ')'){
            if (opening == 0) closing++;
            else opening--;
        }
        else{
            opening++;
        }
    }

    if ((opening+closing)%2 == 1) return -1;

    return (opening/2 + opening%2 + closing/2 + closing%2);
}