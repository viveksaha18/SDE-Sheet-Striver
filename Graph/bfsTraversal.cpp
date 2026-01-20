#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        queue<int> q;
        int vis[n] = {0};
        vis[0] = 1;
        vector<int> ans;
        q.push(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1},
        {2}
    };
    vector<int> result = s.bfs(adj);
    for(int node : result) {
        cout << node << " ";
    }
    return 0;
}