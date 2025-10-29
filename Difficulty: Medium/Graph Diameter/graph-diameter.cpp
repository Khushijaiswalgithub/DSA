class Solution {
  public:
   void dfs(int node,int parent,int dist,int &maxi,int &f,vector<vector<int>>& adj){
       if(dist>maxi){
           f=node;
           maxi=dist;
       }
       for(int ngr:adj[node]){
           if(ngr!=parent){
               dfs(ngr,node,dist+1,maxi,f,adj);
           }
       }
   }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int f=0;
        int maxi=-1;
        dfs(0,-1,0,maxi,f,adj);
        maxi=-1;
        dfs(f,-1,0,maxi,f,adj);
        return maxi;
        
    }
};
