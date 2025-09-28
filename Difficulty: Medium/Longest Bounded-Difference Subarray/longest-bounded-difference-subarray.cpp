class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
    deque<int> minD, maxD;
    int left = 0, bestL = 0, bestLen = 0;

    for (int right = 0; right < n; right++) {
        while (!minD.empty() && arr[minD.back()] >= arr[right]) 
            minD.pop_back();
        minD.push_back(right);
        while (!maxD.empty() && arr[maxD.back()] <= arr[right]) 
            maxD.pop_back();
        maxD.push_back(right);
        while (!minD.empty() && !maxD.empty() &&
               arr[maxD.front()] - arr[minD.front()] > x) {
            if (minD.front() == left) minD.pop_front();
            if (maxD.front() == left) maxD.pop_front();
            left++;
        }
        int len = right - left + 1;
        if (len > bestLen) {
            bestLen = len;
            bestL = left;
        }
    }
    return vector<int>(arr.begin() + bestL, arr.begin() + bestL + bestLen);
    }
};