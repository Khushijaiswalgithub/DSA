class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n=arr.size();
        // Code here
        int x=n/3;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second>x){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};