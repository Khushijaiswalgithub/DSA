//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(int node,vector<vector<int>> &adj,vector<int>&visited){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        vector<int>l;
        while(!q.empty()){
            
            
                int nn=q.front();
                q.pop();
                l.push_back(nn);
                for(auto it:adj[nn]){
                    if(!visited[it]){
                        visited[it]=1;
                        q.push(it);
                    }
                }
            
        }
        return l;
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        vector<int>visited(n,0);
        return bfs(0,adj,visited);
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends