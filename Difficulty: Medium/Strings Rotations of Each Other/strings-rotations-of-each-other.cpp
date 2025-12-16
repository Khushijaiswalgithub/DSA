class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        string s=s2+"$"+s1+s1;
        int n=s.size();
        int m=s2.size();
        int i=0;
        int j=1;
        vector<int>lps(n,0);
        while(j<n){
            if(s[i]==s[j]){
                lps[j++]=++i;
                if(i==m) return true;
            }
            else if(i){
                i=lps[i-1];
            }
            else j++;
        }
        return false;
    }
};