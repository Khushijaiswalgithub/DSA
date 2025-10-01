class Solution {
  public:
    void f(int n,vector<int>&arr,set<vector<int>>&res,vector<int>&r,vector<int>&freq){
    
         if(r.size()==n){ 
            res.insert(r);
            return;
        }
        for(int ind=0;ind<n;ind++){
        if(!freq[ind]){
            r.push_back(arr[ind]);
            freq[ind]=1;
            f(n,arr,res,r,freq);
            r.pop_back();
            freq[ind]=0;
        }
        
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        int n=arr.size();
        set<vector<int>>res;
        vector<int>r;
        vector<int>freq(n,0);
        
        f(n,arr,res,r,freq);
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
        
    }
};