#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution{
private:
    
    void dfs_util(vector<vector<int>>& adj, vector<bool>& vis, int node, vector<int>& result){
        vis[node] = true;
        result.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs_util(adj, vis, it, result);
            }
        }
    }
public:
    vector<int> dfs(vector<vector<int>>& adj){
        int V = adj.size();

        vector<bool> vis(V, false);
        vector<int> result;
        dfs_util(adj, vis, 0, result);
        return result;
    }

};

int main(){
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
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}