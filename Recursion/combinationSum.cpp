#include<bits/stdc++.h>
using namespace std;
// Time Complexity : O(2^n)
// Space Complexity : O(target)
class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;
void f(int idx, int target, vector<int>& candidates) {
    if(idx == candidates.size() || target < 0) return;
    if(target == 0) {
        ans.push_back(temp);
        return;
    }
    temp.push_back(candidates[idx]);
    f(idx, target-candidates[idx], candidates);
    temp.pop_back();
    f(idx+1, target, candidates);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // f(idx, set<vector<int> ans, vector<int>temp, target, vector<vector<int>>candidates)
        f(0, target, candidates);
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 8;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}