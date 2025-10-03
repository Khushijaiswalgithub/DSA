class Solution {
public:
    void f(int ind, vector<int>& arr, unordered_map<int,string>& mp, 
           string &res, vector<string>& ans) {
        if(ind == arr.size()) {
            ans.push_back(res);
            return;
        }
       if(arr[ind]==1 || arr[ind]==0){
           f(ind+1,arr,mp,res,ans);
           return;
           
       }
        string s = mp[arr[ind]];
        for(char c : s) {
            res.push_back(c);
            f(ind + 1, arr, mp, res, ans);
            res.pop_back();
        }
    }

    vector<string> possibleWords(vector<int> &arr) {
        unordered_map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        vector<string> ans;
        string res = "";
        f(0, arr, mp, res, ans);
        return ans;
    }
};
