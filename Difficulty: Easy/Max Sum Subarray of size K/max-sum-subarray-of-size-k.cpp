class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
    if (k > n) return -1;
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxi= windowSum;
    for (int i = k; i < n; i++) {
        windowSum = windowSum + arr[i] - arr[i - k];
        maxi= max(maxi, windowSum);
    }

    return maxi;
    }
};