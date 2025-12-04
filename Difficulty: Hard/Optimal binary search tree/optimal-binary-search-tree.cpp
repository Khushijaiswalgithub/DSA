class Solution {
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        // code here
        int n = keys.size();
        
        // dp[i][j] will store the minimum cost of BST from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // prefix sum to quickly calculate freq sum
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + freq[i];
        
        auto getSum = [&](int l, int r) {
            return prefix[r+1] - prefix[l];
        };
        
        // fill dp for length 1 (single keys)
        for(int i = 0; i < n; i++)
            dp[i][i] = freq[i];
        
        // build larger segments
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                // try every key as root
                for(int r = i; r <= j; r++) {
                    int cost = (r > i ? dp[i][r-1] : 0) +
                               (r < j ? dp[r+1][j] : 0) +
                               getSum(i, j);
                    
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[0][n-1];
    
    }
};