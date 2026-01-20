#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*, Node*> mpp;
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        queue<Node*> q;
        q.push(node);
        Node* first = new Node(node->val);
        mpp[node] = first;
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for(auto adj : curr->neighbors) {
                if(mpp.find(adj) == mpp.end()) {
                    mpp[adj] = new Node(adj->val);
                    q.push(adj);
                }
                mpp[curr]->neighbors.push_back(mpp[adj]);
            }
           
        }
        return mpp[node];
    }
};
int main() {
    Solution s;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};
    Node* clonedGraph = s.cloneGraph(node1);
    cout << "Cloned graph node value: " << clonedGraph->val << endl;
    return 0;
}