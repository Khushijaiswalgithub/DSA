class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
         unordered_map<int, int> prefixSumCount;
    int currentSum = 0, count = 0;

    prefixSumCount[0] = 1; 

    for (int num : arr) {
        currentSum += num;

        if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - k];
        }

        prefixSumCount[currentSum]++;
    }

    return count;
    }
};