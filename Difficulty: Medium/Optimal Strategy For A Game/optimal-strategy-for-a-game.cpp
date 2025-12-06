class Solution {
  public:
    int maximumAmount(vector<int> &arr) {
        // code here
        int n=arr.size();
         vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // length of subarray
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j < n; i++, j++){

                if(g == 0){
                    dp[i][j] = arr[i];
                }
                else if(g == 1){
                    dp[i][j] = max(arr[i], arr[j]);
                }
                else {
                    long long a = dp[i+2][j];     // if player picks i, opponent picks i+1
                    long long b = dp[i+1][j-1];   // opponent picks j
                    long long c = dp[i][j-2];     // if player picks j, opponent picks j-1

                    dp[i][j] = max(
                        arr[i] + min(a, b),
                        arr[j] + min(b, c)
                    );
                }
            }
        }

        return dp[0][n-1];
    
    }
};