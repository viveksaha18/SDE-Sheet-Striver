#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N*N)
// Space Complexity: O(N*N)
class Solution {
public:
vector<vector<int>> ans;
void duplicateMatrix(int col, int n, vector<vector<int>>& matrix) {
    vector<int> arr;
    for(int row = 0; row < n; row++) {
        arr.push_back(matrix[row][col]);
    }
    reverse(arr.begin(), arr.end());
    ans.push_back(arr);
}
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // columns
        for(int i = 0; i < m; i++) {
            duplicateMatrix(i, n, matrix);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = ans[i][j];
            }
        }
        
    }
};
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution sol;
    sol.rotate(matrix);
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}