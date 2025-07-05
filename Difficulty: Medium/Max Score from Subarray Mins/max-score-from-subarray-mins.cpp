class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int ans=0;
        int n=arr.size();
        for(int i=1;i<n;i++){
            ans=max(ans,arr[i]+arr[i-1]);
        }
        return ans;
    }
};