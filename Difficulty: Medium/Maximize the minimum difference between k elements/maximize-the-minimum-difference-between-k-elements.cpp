class Solution {
  public:
    bool valid(int mid,vector<int>& arr, int k){
        int n=arr.size();
        int p=arr[0];
        int c=1;
      for(int i=1;i<n;i++){
          int d=arr[i]-p;
          if(d>=mid){
              c++;
              p=arr[i];
              
          }
          if(c==k){
              return true;
          }
      }
      return false;
    }
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int l=0;
        int r=arr[n-1]-arr[0];
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(valid(mid,arr,k)){
                l=mid+1;
                ans=max(ans,mid);
            }
            else{
                r=mid-1;
                
            }
            
            
        }
        return ans;
        
    }
};
