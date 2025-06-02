class Solution {
  public:
    int dfs(int r, int c, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if (r >= n || c >= m || grid[r][c] == 1) return 0;
    if (r == n - 1 && c == m - 1) return 1;

    if (dp[r][c] != -1) return dp[r][c];
    int right = dfs(r, c + 1, n, m, grid, dp);
    int down = dfs(r + 1, c, n, m, grid, dp);

    return dp[r][c] = right + down;
}

int uniquePaths(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return 0;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return dfs(0, 0, n, m, grid, dp);
}

};