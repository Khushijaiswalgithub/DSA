//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node,vector<int>&cur,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        cur[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,cur,vis,adj)){
                    return true;
                }
            }
                
            else if(cur[it]==1){
                return true;
                
            }
        }
        cur[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            vector<int>cur(V,0);
            if(dfs(i,vis,cur,adj)){
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends