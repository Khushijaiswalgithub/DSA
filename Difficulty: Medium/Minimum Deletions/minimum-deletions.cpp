class Solution {
  public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i - 1] == s2[j - 1]) {
        return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
    }
    return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
}

int minDeletions(string s) {
    int n = s.size();
    string s1 = s;
    reverse(s.begin(), s.end());
    string s2 = s;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int lps = f(n, n, s1, s2, dp);
    return n - lps;
}
};