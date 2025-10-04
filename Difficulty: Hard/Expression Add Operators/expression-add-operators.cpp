class Solution {
  public:
    vector<string> ans;

    void dfs(string &s, int pos, long long curVal, long long prevNum,
             string expr, long long target) {
        if (pos == s.size()) {
            if (curVal == target) ans.push_back(expr);
            return;
        }

        for (int i = pos; i < s.size(); i++) {
            if (i != pos && s[pos] == '0') break;

            string part = s.substr(pos, i - pos + 1);
            long long num = stoll(part);

            if (pos == 0) {
                
                dfs(s, i + 1, num, num, part, target);
            } else {
                dfs(s, i + 1, curVal + num, num, expr + "+" + part, target);
                dfs(s, i + 1, curVal - num, -num, expr + "-" + part, target);
                dfs(s, i + 1, curVal - prevNum + prevNum * num,
                    prevNum * num, expr + "*" + part, target);
            }
        }
    }

    vector<string> findExpr(string &s, int target) {
        // code here
       ans.clear();
        dfs(s, 0, 0, 0, "", target);
        sort(ans.begin(), ans.end()); 
        return ans;
        
        
    }
};