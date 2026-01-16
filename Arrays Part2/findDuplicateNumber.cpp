#include<bits/stdc++.h>
using namespace std;
// Time Complexity : O(n)
// Space Complexity : O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int x : nums) {
            mpp[x]++;
        }
        for(auto it : mpp) {
            if(it.second > 1) return it.first;
        }
        return 0;
    }
};
int main() {
    return 0;
}