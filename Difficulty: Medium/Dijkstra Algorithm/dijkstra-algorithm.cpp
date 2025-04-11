//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
           int u = edge[0], v = edge[1], wt = edge[2];
           adj[u].push_back({v, wt});
           adj[v].push_back({u, wt}); 
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(V,1e9);
        dis[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            int dnode=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int d=it.second;
                int e=it.first;
                if(dnode+d<dis[e]){
                    dis[e]=dnode+d;
                    pq.push({dis[e],e});
                }
            }
        }
        return dis;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends