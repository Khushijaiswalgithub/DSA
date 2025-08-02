class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n=arr.size();
        vector<int>pre(n);
        if(arr[0]>k) pre[0]=1;
        else pre[0]=-1;
        for(int i=1;i<n;i++){
            if(arr[i]>k){
                pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=pre[i-1]-1;
            }
        }
        unordered_map<int,int>mp;
        int maxi=0;
        for(int i=0;i<n;i++){
            
            if(pre[i]>0){
                maxi=max(maxi,i+1);
            }
            else{
                if(mp.find(pre[i]-1)!=mp.end()){
                    maxi=max(maxi,i-mp[pre[i]-1]);
                }
            }
            if(mp.find(pre[i])==mp.end()){
                mp[pre[i]]=i;
            }
        }
        return maxi;
    }
};