class Solution {
  public:
   

vector<int> solve(vector<int>& arr, int i, int last, vector<vector<vector<int>>>& dp) {
    if (i == arr.size()) return {};

    if (!dp[i][last + 1].empty()) return dp[i][last + 1];

    vector<int> take;
    if (last == -1 || arr[i] % arr[last] == 0) {
        take = solve(arr, i + 1, i, dp);
        take.insert(take.begin(), arr[i]);
    }

    vector<int> nottake = solve(arr, i + 1, last, dp);

    if (nottake.size() > take.size() || 
        (nottake.size() == take.size() && nottake > take)) {
        return dp[i][last + 1] = nottake;
    } else {
        return dp[i][last + 1] = take;
    }
}

vector<int> largestSubset(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // Create a 3D dp table to store vectors at each [i][last+1]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1));
    return solve(arr, 0, -1, dp);
}

    
};