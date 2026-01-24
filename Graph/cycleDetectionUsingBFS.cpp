#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n) + O(2E)  where n is number of nodes and E is number of edges

class Solution {
  public:
     bool detect(int src, vector<int> &vis, vector<vector<int>>&adjls)
    {
        vis[src]=1;
        
        queue<pair<int,int>>q;
        
        q.push({src,-1});
        
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto itr:adjls[node])
            {
                if(vis[itr]==0)
                {
                    vis[itr]=1;
                    q.push({itr,node});
                }
                else if(parent!=itr)
                {
                    return true;
                }
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adjls(V);
        
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            adjls[edges[i][0]].push_back(edges[i][1]);
            adjls[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0) 
            {
                if(detect(i,vis,adjls)==true) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3}
    };
    bool hasCycle = s.isCycle(V, edges);
    if (hasCycle) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }
    return 0;
}