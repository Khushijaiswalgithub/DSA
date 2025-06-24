class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
       int n = s.length();
    string result = "";
    
    for (char c : s) {
        while (!result.empty() && k > 0 && result.back() < c) {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }

    // If deletions are still left
    while (k--) {
        result.pop_back();
    }

    return result;
        
    }
};
