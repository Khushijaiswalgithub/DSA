class Solution {
  public:
    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move, vector<vector<int>> &vis) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        string dir = "DLRU";

        for (int k = 0; k < 4; k++) {
            int nexti = i + di[k];
            int nextj = j + dj[k];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
                !vis[nexti][nextj] && m[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, m, n, ans, move + dir[k], vis);
                vis[i][j] = 0;
            }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n=maze.size();
         vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (maze[0][0] == 0) return ans;  
        solve(0, 0, maze, n, ans, "", vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};