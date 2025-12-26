#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach : TC : O(n*m) SC : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};
// Better Solution : TC : O(n + logm) SC : O(1)
class Solution1 {
public:
bool bs(vector<int> v, int target) {
    int n = v.size();
    int low = 0;
    int high = n-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(v[mid] == target) return true;
        if(v[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] <= target && target <= matrix[i][m-1]) {
                return bs(matrix[i], target);
            }
        }
        return false;
    }
};

// Optimal Solution : TC : O(log(n*m)) SC : O(1)
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = m*n-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
int main() {
    Solution1 obj;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    bool result = obj.searchMatrix(matrix, target);
    cout << (result ? "True" : "False") << endl;
    return 0;
}