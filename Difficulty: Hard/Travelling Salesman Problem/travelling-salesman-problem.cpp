class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        int FULL_MASK = (1 << n);
        
        // dp[mask][i] = min cost to reach city i with visited cities = mask
        vector<vector<int>> dp(FULL_MASK, vector<int>(n, -1));
        
        function<int(int,int)> solve = [&](int mask, int i) {
            // If all cities visited, return cost to go back to starting city 0
            if (mask == FULL_MASK - 1)
                return cost[i][0];
            
            if (dp[mask][i] != -1)
                return dp[mask][i];
            
            int ans = INT_MAX;
            
            // Try next unvisited cities
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) { // if j not visited
                    int newCost = cost[i][j] + solve(mask | (1 << j), j);
                    ans = min(ans, newCost);
                }
            }
            
            return dp[mask][i] = ans;
        };
        
        // Start from city 0, visited mask = 1
        return solve(1, 0);
    }
};
