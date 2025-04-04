//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool detect(int i,vector<int>&vis,vector<vector<int>>& edges){
      vis[i]=1;
      queue<pair<int,int>>q;
      q.push({i,-1});
      while(!q.empty()){
          int node=q.front().first;
          int parent=q.front().second;
          
          for(auto adj:edges[node]){
              if(!vis[adj]){
                  q.push({adj,node});
              }
              else{
                  if(adj!=parent){
                      return true;
                  }
              }
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if(detect(i,vis,edges)){
                    return true;
                }
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends