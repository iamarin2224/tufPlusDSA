#include <bits/stdc++.h>
using namespace std;

bool checkIthBit(int n, int i) {
    return (bool)((n>>i)&1);
}