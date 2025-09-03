#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
} 

int minBitsFlip(int start, int goal) { 
    return countSetBits(start^goal);
}