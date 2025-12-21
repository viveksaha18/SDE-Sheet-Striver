#include<bits/stdc++.h>
using namespace std;

// First Approach Using Set to Avoid Duplicates
// Time Complexity : O(n * 2^n)+O(nlogn) (nlogn for sorting and n*2^n for generating subsets)
// Space Complexity : O(2^n) (for storing subsets in set) here i can optimze it is an extra space used just for duplicates
class Solution {
public:
set<vector<int>>st;
void f(int currIdx, vector<int>& temp, vector<int>& arr) {
    if(currIdx > arr.size()) return;
    if(currIdx == arr.size()) {
        st.insert(temp);
        return;
    }
    temp.push_back(arr[currIdx]);
    f(currIdx+1, temp, arr);
    temp.pop_back();
    f(currIdx+1, temp, arr);
}
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> temp;
        f(0, temp, arr);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
int main() {
    Solution obj;
    vector<int> arr = {1,2,2};
    vector<vector<int>> result = obj.subsetsWithDup(arr);
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}