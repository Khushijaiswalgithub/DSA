//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   void dfs(int node,vector<int>adj[],vector<int>&vis,int c,int d){
       vis[node]=1;
       for(auto it:adj[node]){
           if(vis[it]!=1 && !(node==c && it==d)){
               dfs(it,adj,vis,c,d);
               
           }
       }
   }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<int>vis(V,0);
        dfs(c,adj,vis,c,d);
        if(vis[d]){
            return false;
        }
        return true;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends