#include <iostream>
using namespace std;

//? Brute
int candy(vector<int>& ratings) {
    int n = ratings.size();

    int left[n];
    int right[n];

    left[0] = 1;

    for(int i=1; i<n; i++){
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i]=1;
        }
    }

    right[n-1] = 1;

    for(int i=n-2; i>=0; i--){
        if(ratings[i] > ratings[i+1]){
            right[i] = right[i+1]+1;
        }
        else{
            right[i]=1;
        }
    }

    int sum = 0;

    for(int i=0; i<n; i++){
        sum += max(left[i], right[i]);
    }

    return sum;
}

//? Better
int candy(vector<int>& ratings) {
    int n = ratings.size();

    int left[n];

    left[0] = 1;

    for(int i=1; i<n; i++){
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i]=1;
        }
    }

    int cur = 1; //Number of candies to be given to current
    int right = 1; //Stores number of candies given to right

    int sum = max(left[n-1], 1);

    for(int i=n-2; i>=0; i--){
        if(ratings[i] > ratings[i+1]){
            cur = right+1;
        }
        else{
            cur = 1;
        }
        right = cur;
        sum += max(left[i], cur);
    }

    return sum;
}

//? Optimal -> Concept of slope
int candy(vector<int>& ratings) {
    int n = ratings.size();

    int sum = 1;
    int i = 1;

    while (i<n){
        // Flat surface
        if (ratings[i] == ratings[i-1]){
            sum++; i++;
            continue;
        }

        // Going up
        int peak = 1;
        while (i<n && ratings[i] > ratings[i-1]){
            //Assumed starts from peak so first increment it then add
            peak++;
            sum += peak; i++;
        }

        // Going down
        int down = 1;
        while(i<n && ratings[i] < ratings[i-1]){
            // For the down the peak element is added in sum so add the next down then increment
            sum += down; i++;
            down++;
        }

        // Adjusting the sum 
        if (down > peak){
            sum += (down-peak);
        }
    }

    return sum;
}