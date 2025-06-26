class Solution {
  public:
    int minValue(string &s, int k) {
    vector<int> f(26, 0);
    for (char ch : s) {
        f[ch - 'a']++;
    }

    priority_queue<int> st;
    for (int count : f) {
        if (count > 0) {
            st.push(count);
        }
    }

    while (!st.empty() && k > 0) {
        int x = st.top();
        st.pop();
        x--;  // remove one occurrence of the most frequent character
        k--;
        if (x > 0) {
            st.push(x);
        }
    }

    int ans = 0;
    while (!st.empty()) {
        int val = st.top();
        st.pop();
        ans += val * val;
    }

    return ans;
}

};