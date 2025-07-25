class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int sum=arr[0];
        int maxi=arr[0];
        int sum2=arr[0];
        int t=arr[0];
        int mini=arr[0];
        for(int i=1;i<n;i++){
            
        
            t+=arr[i];
            
            sum=max(arr[i],sum+arr[i]);
            
            maxi=max(maxi,sum);
            
            
            sum2=min(arr[i],sum2+arr[i]);
            

            mini=min(mini,sum2);
            
            
            
            
        }
        if (maxi < 0)return maxi;
        return max(maxi,t-mini);
    }
};