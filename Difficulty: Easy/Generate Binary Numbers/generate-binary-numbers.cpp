class Solution {
  public:
    string deci(int n){
        string ans="";
        while(n!=0){
            ans+=((n%2)+'0');
            n=n/2;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<string> generateBinary(int n) {
        // code here
        vector<string>ans;
        
        for(int i=1;i<=n;i++){
            string x=deci(i);
            ans.push_back(x);
        }
        return ans;
    }
};