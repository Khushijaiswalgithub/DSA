class Solution {
  public:
    void f(int ind,int n,int k,int &sum,vector<vector<int>>&ans,vector<int>&res){
        
        if(ind>9 || res.size()==k){
            if(sum==n && res.size()==k) ans.push_back(res);
            return;
        }
        res.push_back(ind);
        sum+=ind;
        
        f(ind+1,n,k,sum,ans,res);
        res.pop_back();
        sum-=ind;
        f(ind+1,n,k,sum,ans,res);
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>>ans;
        vector<int>res;
        int sum=0;
        f(1,n,k,sum,ans,res);
        return ans;
        
    }
};