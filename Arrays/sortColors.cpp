#include<bits/stdc++.h>
using namespace std;
// Brute Force Approach - TC-O(nlogn)
void sortColors(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

// Optimal Version 
// TC - O(n)
void sortColorsOptimalVersion(vector<int>& arr) {
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(auto it : arr) {
        if(it == 0) cnt0++;
        else if(it == 1) cnt1++;
        else cnt2++;
    }
    int idx = 0;
    for(int i = 0; i < cnt0; i++) arr[idx++] = 0;
    for(int i = 0; i < cnt1; i++) arr[idx++] = 1;
    for(int i = 0; i < cnt2; i++) arr[idx++] = 2;
}
int main() {
    vector<int> nums = {0,2,1,1,2,0};
    sortColors(nums);
    for(int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;
    vector<int> arr = {0, 1, 2, 1, 1, 0};
    sortColorsOptimalVersion(arr);
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    return 0;
}