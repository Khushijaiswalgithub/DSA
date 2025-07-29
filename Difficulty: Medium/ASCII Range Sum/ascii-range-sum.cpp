class Solution {
  public:
    vector<int> asciirange(string& s) {
    int n = s.size();
    unordered_map<char, int> firstPos;
    unordered_map<char, int> lastPos;

    
    for (int i = 0; i < n; ++i) {
        if (firstPos.find(s[i]) == firstPos.end())
            firstPos[s[i]] = i;
        lastPos[s[i]] = i;
    }

    
    vector<int> asciiSum(n, 0);
    asciiSum[0] = s[0];
    for (int i = 1; i < n; ++i) {
        asciiSum[i] = asciiSum[i - 1] + s[i];
    }


    vector<int> ans;
    unordered_set<char> visited;

    for (char ch : s) {
        if (visited.count(ch)) continue;
        visited.insert(ch);
        int first = firstPos[ch];
        int last = lastPos[ch];
        if (last > first + 1) {
            int sumBetween = asciiSum[last - 1] - asciiSum[first];
            ans.push_back(sumBetween);
        }
    }

    return ans;
}
};