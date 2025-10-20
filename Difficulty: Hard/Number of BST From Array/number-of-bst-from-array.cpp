class Solution {
  public:
  vector<int> catalan(int n) {
    vector<int> C(n + 1, 0);
    C[0] = C[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            C[i] += C[j] * C[i - j - 1];
        }
    }
    return C;
}
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
         int n = arr.size();
    vector<int> res(n);
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    vector<int> C = catalan(n);

    unordered_map<int, int> mp; 
    for (int i = 0; i < n; i++) {
        int left = i;
        int right = n - i - 1;
        mp[sortedArr[i]] = C[left] * C[right];
    }

    for (int i = 0; i < n; i++) {
        res[i] = mp[arr[i]];
    }

    return res;
    }
};