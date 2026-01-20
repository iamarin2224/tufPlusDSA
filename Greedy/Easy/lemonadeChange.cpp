#include <iostream>
using namespace std;

bool lemonadeChange(vector<int>& bills){
    int five = 0, ten = 0;

    for (int i=0; i<bills.size(); i++){
        if (bills[i] == 5){
            five++;
        }

        else if (bills[i] == 10){
            if (!five) return false;

            five--, ten++;
        }

        else if (bills[i] == 20){
            if (!five) return false;

            if (!ten){
                if (five < 3) return false;
                five -= 3;
            }
            else{
                ten--, five--;
            }
        }
    }

    return true;
}