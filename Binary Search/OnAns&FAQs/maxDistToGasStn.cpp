#include <iostream>
using namespace std;

//!Brute
//Considers the gap between given positions as section and keeps a count of number of gas stn placed in the gaps till now and adjusts the posn as and when required

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    //To keep count of number of gas stn placed in each section 
    vector<int> howMany(n-1, 0);

    //Loop to place each section
    for (int gasStn = 1; gasStn <= k; gasStn++){
        //Store the maxlen and where the maxlen occurs (max ind) , we need to place our current gas stn there
        double maxSetionLen = -1;
        double maxInd = -1;

        //Loop to calculate the max dist till now, by carefully dividing the section into equal parts based on number of gas stn placed till now
        for (int i=0; i<n-1; i++){
            double diff = arr[i+1] - arr[i];
            double sectionLen = diff/(double)(howMany[i]+1);

            if (sectionLen > maxSetionLen){
                maxSetionLen = sectionLen;
                maxInd = i;
            }
        }

        //Placing the gas stn at that position
        howMany[maxInd]++;
    }

    //Seperate loop to find out the max length btw gas stn (section len) after placing all the gas stn
    double maxAns = -1;
    for (int i=0; i<n-1; i++){
        double diff = arr[i+1] - arr[i];
        double sectionLen = diff/(double)(howMany[i]+1);
        maxAns = max(maxAns, sectionLen);
    }

    return maxAns;
}

//!Better 
//? --> Using Priority Queue on the same idea

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    //To keep count of number of gas stn placed in each section 
    vector<int> howMany(n-1, 0);

    priority_queue<pair<long double, int>> pq;
    
    //Initialising the priority queue
    for (int i=0; i<n-1; i++){
        pq.push({(long double)(arr[i+1]-arr[i]), i});
    }

    //Loop to place each section
    for (int gasStn = 1; gasStn <= k; gasStn++){
        //Fetching then removing the top as we will be altering it
        auto tp = pq.top();
        pq.pop();

        int secInd = tp.second;

        //Inserting the gasStn
        howMany[secInd]++;

        //Calculating the new section length and inserting it
        long double initialDiff = (long double)(arr[secInd+1]-arr[secInd]);
        long double newSecLen = initialDiff/(long double)(howMany[secInd] + 1);

        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}

//! Binary Search ~ Optimal

int maxDistance(vector<int> &arr){
    int maxDist = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n-1; i++){
        int dist = arr[i+1] - arr[i];
        maxDist = max(maxDist, dist);
    }
    return maxDist;
}

int numOfGasStnReq(vector<int> &arr, long double dist){
    int n = arr.size();
    int cnt = 0;

    for (int i=0; i<n-1; i++){
        //below method works because dist is the max dist, gas stn placed at lesser dist b/w them is allowed
        int numInBtw = (arr[i+1]-arr[i])/dist;

        //if a perfect integer, then we have to reduce it by one (as for 1->2 with dist=0.5 only one stn possible)
        if ((arr[i+1]-arr[i]) == numInBtw * dist) numInBtw--;

        cnt += numInBtw;
    }

    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    long double low = 0, high = (long double)maxDistance(arr);

    while (high-low > 1e-6){
        long double mid = (low + high)/2.0;

        int cnt = numOfGasStnReq(arr, mid);

        if (cnt > k) low = mid;
        else high = mid;
    }

    return high;
}