#include<bits/stdc++.h>
using namespace std;
// Using map Data Structure
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++) mpp[nums[i]]++;
        for(auto it : mpp) {
            if(it.second > n/2) return it.first;
        }
        return 0;
    }
};
int main() {
    Solution s;
    vector<int> nums = {3,2,3};
    cout << s.majorityElement(nums) << endl;
    return 0;
}