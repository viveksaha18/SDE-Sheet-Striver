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
// Optimal Approach using Moore's Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                cnt=1;
                el = nums[i];
            }
            else if(el == nums[i]) cnt++;
            else cnt--;
        }
        return el;
    }
};
int main() {
    Solution s;
    vector<int> nums = {3,2,3};
    cout << s.majorityElement(nums) << endl;
    Solution s1;
    vector<int> nums1 = {2,2,1,1,1,2,2};
    cout << s1.majorityElement(nums1) << endl;
    return 0;
}