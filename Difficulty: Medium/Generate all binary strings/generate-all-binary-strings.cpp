class Solution {
  public:
    void f(int n,string s,vector<string>&res){
        if(s.size()==n){
            res.push_back(s);
            return;
        }
        s+="0";
        f(n,s,res);
        s.pop_back();
        s+="1";
        f(n,s,res);
        
    }
    vector<string> binstr(int n) {
        // code here
        vector<string>res;
        f(n,"",res);
        return res;
        
    }
};