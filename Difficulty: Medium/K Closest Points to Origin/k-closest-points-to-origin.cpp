class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<pair<double,vector<int>>>maxh;
        for(auto it:points){
            int x=it[0];
            int y=it[1];
            double d=sqrt(x*x+y*y);
            maxh.push({d,{x,y}});
            if(maxh.size()>k){
                maxh.pop();
            }
            
        }
        vector<vector<int>>ans;
        while(!maxh.empty()){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
        
    }
};