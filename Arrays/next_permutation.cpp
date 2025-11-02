#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = n-1; i > idx; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+idx+1, nums.end());
        for(int i = 0; i < n; i++) cout << nums[i];
    }
};
int main() {
    Solution s;
    vector<int> nums = {2,1,5,4,3,0,0};
    s.nextPermutation(nums);
    return 0;
}