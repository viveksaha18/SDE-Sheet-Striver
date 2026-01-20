#include<bits/stdc++.h>
using namespace std;
// Using map Data Structure
// TC: O(n)
// SC : O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(auto it : nums) {
            mpp[it]++;
        }
        for(auto it : mpp) {
            if(it.second > n/3) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}