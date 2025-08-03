class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                 vector<vector<int>>& opr) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));

    for (auto& it : opr) {
        int val = it[0];
        int r1 = it[1];
        int c1 = it[2];
        int r2 = it[3];
        int c2 = it[4];

        diff[r1][c1] += val;
        if (c2 + 1 < m) diff[r1][c2 + 1] -= val;
        if (r2 + 1 < n) diff[r2 + 1][c1] -= val;
        if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += val;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            diff[i][j] += diff[i][j - 1];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            diff[i][j] += diff[i - 1][j];
        }
    }
    vector<vector<int>> res(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = mat[i][j] + diff[i][j];
        }
    }

    return res;
}

};