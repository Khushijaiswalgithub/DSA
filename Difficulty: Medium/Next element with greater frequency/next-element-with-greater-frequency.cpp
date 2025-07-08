class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }

    vector<int> result(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        int currentFreq = freq[arr[i]];
        while (!st.empty() && freq[st.top()] <= currentFreq) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }

    return result;
    }
};
