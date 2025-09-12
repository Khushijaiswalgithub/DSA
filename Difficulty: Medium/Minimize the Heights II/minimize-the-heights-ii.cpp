class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int s=arr[0];
        int l=arr[n-1];
        int ans=l-s;
        for(int i=1;i<n;i++){
            s=min(arr[0]+k,arr[i]-k);
            l=max(arr[n-1]-k,arr[i-1]+k);
            if(s<0) continue;
            ans=min(ans,l-s);
            
        }
        return ans;
        
        
    }
};