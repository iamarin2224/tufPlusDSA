#include <iostream>
using namespace std;

int findMaximumCookieStudents(vector<int>& student, vector<int>& cookie){
    sort(student.begin(), student.end());
    sort(cookie.begin(), cookie.end());

    int stuPtr = 0, cookiePtr = 0;

    while (stuPtr<student.size() && cookiePtr<cookie.size()){
        if (cookie[cookiePtr] >= student[stuPtr]){
            cookiePtr++;
            stuPtr++;
        }
        else{
            cookiePtr++;
        }
    }

    return stuPtr;
}