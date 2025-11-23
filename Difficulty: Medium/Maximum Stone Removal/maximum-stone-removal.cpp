class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
         int n = stones.size();
        
        // Graph: adjacency list
        unordered_map<int, vector<int>> rowMap, colMap;
        
        for (int i = 0; i < n; i++) {
            rowMap[stones[i][0]].push_back(i);  // stones in same row
            colMap[stones[i][1]].push_back(i);  // stones in same column
        }

        vector<int> visited(n, 0);

        function<void(int)> dfs = [&](int idx) {
            visited[idx] = 1;

            int x = stones[idx][0];
            int y = stones[idx][1];

            // visit all stones in same row
            for (int nei : rowMap[x])
                if (!visited[nei])
                    dfs(nei);

            // visit all stones in same column
            for (int nei : colMap[y])
                if (!visited[nei])
                    dfs(nei);
        };

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i);
            }
        }

        return n - components;
    }
};