class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int s=arr[0][0];
        int e=arr[0][1];
        vector<vector<int>>ans;
        for(auto it:arr){
            if(it[0]<=e){
                e=max(e,it[1]);
            }
            else{
                ans.push_back({s,e});
                s=it[0];
                e=it[1];
                
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};