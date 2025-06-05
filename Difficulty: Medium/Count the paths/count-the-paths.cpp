class Solution {
  public:
    int dfs(vector<vector<int>>&adj,vector<int>&dp,int node,int dest){
        if(node==dest){
            
            return 1;
        }
        if(dp[node]!=-1) return dp[node];
        int p=0;
        for(auto it:adj[node]){
            p+=dfs(adj,dp,it,dest);
        }
        return dp[node]=p;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int>dp(V,-1);
        return dfs(adj,dp,src,dest);
        
        
    }
};