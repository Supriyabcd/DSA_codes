//Driver Code Starts
#include <iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> bfs;
        
        vector<int> vis(V, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it :adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
