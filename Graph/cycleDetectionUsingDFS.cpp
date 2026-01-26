#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  bool dfs(int src, int parent, vector<vector<int>>& adj, int vis[]) {
      vis[src] = 1;
      for(auto it : adj[src]) {
          if(!vis[it]) {
              if(dfs(it, src, adj, vis)) {
                  return true;
              }
          }
          else if(it != parent) return true;
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int vis[V] = {0};
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};
int main() {
    Solution s;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    if(s.isCycle(V, edges)) {
        cout << "Graph contains cycle" << endl;
    } else {
        cout << "Graph doesn't contain cycle" << endl;
    }
    return 0;
}