#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
  public:
  vector<int> ans;
  void dfs(int node, vector<vector<int>>& adj, int vis[]) {
      vis[node] = 1;
      ans.push_back(node);
      for(auto it : adj[node]) {
          if(!vis[it]) {
              dfs(it, adj, vis);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        int vis[n] = {0};
        dfs(0, adj, vis);
        return ans;
    }
};
int main() {
    Solution s;
    vector<vector<int>> adj;
    adj = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };
    vector<int> result = s.dfs(adj);
    cout << "DFS Traversal: ";
    for(int node : result) {
        cout << node << " ";
    }
    return 0;
}