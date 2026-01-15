#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
set<vector<int>> ans;
vector<int> temp;
void f(int idx, int target, vector<int>& candidates) {
    if(idx == candidates.size() || target < 0) return;
    if(target == 0) {
        vector<int> check = temp;
        sort(check.begin(), check.end());
        ans.insert(check);
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
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
int main() {
    Solution s;
    vector<int> candidates = {10,1,2,7,6,1,5};
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