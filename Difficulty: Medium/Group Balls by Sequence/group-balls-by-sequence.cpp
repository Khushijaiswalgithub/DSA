class Solution {
  public:
    

bool validgroup(vector<int> &arr, int k) {
    int n = arr.size();
    if (n % k != 0) return false;

    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }

    sort(arr.begin(), arr.end()); // sort to start from smallest elements

    for (int num : arr) {
        if (freq[num] == 0) continue;

        // Try to form a group starting from num
        for (int i = 0; i < k; i++) {
            int val = num + i;
            if (freq[val] == 0) return false;
            freq[val]--;
        }
    }
    return true;
}

};