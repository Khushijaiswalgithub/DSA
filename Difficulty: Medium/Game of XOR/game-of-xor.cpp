class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long freq = 1LL * (i + 1) * (n - i);

            if(freq % 2 == 1) {
                ans ^= arr[i];
            }
        }
        return ans;
    }
};