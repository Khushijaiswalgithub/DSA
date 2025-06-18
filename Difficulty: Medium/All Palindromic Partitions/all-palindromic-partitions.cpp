class Solution {
  public:
    bool palindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

void func(int ind, vector<string>& path, vector<vector<string>>& res, string &s) {
    if (ind == s.size()) {
        res.push_back(path);  
        return;
    }

    for (int i = ind; i < s.size(); i++) {
        string sub = s.substr(ind, i - ind + 1);
        if (palindrome(sub)) {
            path.push_back(sub);
            func(i + 1, path, res, s);
            path.pop_back();
        }
    }
}

vector<vector<string>> palinParts(string &s) {
    vector<string> path;
    vector<vector<string>> res;
    func(0, path, res, s);
    return res;
}

};