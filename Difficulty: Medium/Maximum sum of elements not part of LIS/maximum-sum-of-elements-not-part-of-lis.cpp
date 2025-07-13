class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>dpsum(n);
        
        for(int i=0;i<n;i++){
            dpsum[i]=arr[i];
        }
        int total=accumulate(arr.begin(),arr.end(),0);
        int maxi=1;
        int minsum=arr[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    int c=dp[j]+1;
                    int csum=dpsum[j]+arr[i];
                    if(c>dp[i]){
                        dp[i]=c;
                      
                        dpsum[i]=csum;
                    }
                    else if(c==dp[i]){
                        dpsum[i]=min(dpsum[i],csum);
                    }
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                minsum=dpsum[i];
            }
            else if(dp[i]==maxi){
                minsum=min(minsum,dpsum[i]);
            }
        }
        return total-minsum;
    }
};