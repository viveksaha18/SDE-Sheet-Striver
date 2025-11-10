#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
class Solution {
public:
static bool comp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        int st = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            int newStart = intervals[i][0];
            int newEnd = intervals[i][1];
            if(newStart <= end) {
                end = max(end, newEnd);
            }
            else {
                ans.push_back({st, end});
                st = newStart;
                end = newEnd;
            }
        }
        ans.push_back({st, end});
        return ans;
    }
};
int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 4},
        {5, 7},
        {6, 8}
    };
    Solution sol;
    vector<vector<int>> mergedIntervals = sol.merge(intervals);
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}