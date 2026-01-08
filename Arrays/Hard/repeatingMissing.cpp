#include <iostream>
using namespace std;

//? Own Solution -> TC:O(2*n) SC:O(n)       (Hashing will have similar TC and SC)
// vector<int> findMissingRepeatingNumbers(vector<int> nums) {
//     int n = nums.size();

//     int sumArr = 0;
//     unordered_set<int> st;

//     int xorN = 0, xorArr = 0;

//     for (int i=0; i<n; i++){
//         st.insert(nums[i]);
//         sumArr += nums[i];

//         xorN = xorN ^ (i+1);
//         xorArr = xorArr ^ nums[i];
//     }

//     int sumN = 0;
//     for (int x: st){
//         sumN += x;
//     }

//     int repEle = sumArr - sumN;

//     int xorMR = xorArr ^ xorN;

//     int misEle = repEle ^ xorMR;

//     vector<int> answer = {repEle, misEle};

//     return answer;
// }

//? Summation approach
// vector<int> findMissingRepeatingNumbers(vector<int> nums) {
//     int n = nums.size();

//     long long Sn = (n*(n+1))/2;
//     long long S2n = (n*(n+1)*(2*n+1))/6;

//     long long Sarr = 0, S2arr = 0;

//     for (int i=0; i<n; i++){
//         Sarr += (long long)nums[i];
//         S2arr += (long long)(nums[i] * nums[i]);
//     }

//     long long val1 = Sarr - Sn;
//     long long val2 = S2arr - S2n;

//     val2 = val2/val1;

//     long long x = (val1 + val2)/2;
//     long long y = (val2 - val1)/2;

//     return {(int)x, (int)y};
// }

//? Marking index approach

int findRepeatingNumber(vector<int> nums) {
    int n = nums.size();

    for (int num: nums){
        int idx = abs(num)-1;       
        //each index can be marked by only a specific element in the array, we are not checking for the num, but for the idx the current num marks to 
        if (nums[idx] > 0){
            nums[idx] = -nums[idx];
        }
        //if it is already negative, it means it was marked by its similar element, so this is the repeating number
        else{
            return abs(num);
        }
    }

    return -1;
}


vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    int n = nums.size();

    int repNum = findRepeatingNumber(nums);

    int sumN = (n*(n+1))/2;

    int sumAr = 0;

    for (int i=0; i<n; i++){
        sumAr += nums[i];
    }

    int misNum = sumN - (sumAr - repNum);

    return {repNum, misNum};
}


int main(){

    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> answer = findMissingRepeatingNumbers(nums);

    cout<<"The output is: "<<answer[0]<<" "<<answer[1]<<endl;

    return 0;
}