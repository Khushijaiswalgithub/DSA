class Solution {
  public:
    int f(int n,vector<int>&arr){
        int ans=0;
        for(int i=0;i<arr.size();i++){
            
            ans += ceil((double)arr[i] / n);
        }
        return ans;
        
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        
        int n=arr.size();
        int l=1;
        int r = *max_element(arr.begin(), arr.end());
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            int x=f(mid,arr);
            if (x <= k) {
                ans = mid;
                r = mid - 1;
            } else {
              l = mid + 1;
            }
        }
        return ans;
    }
};