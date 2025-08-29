class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        unordered_map<char,int>mp;
        int m=p.size();
        for(int i=0;i<m;i++){
            mp[p[i]]++;
        }
        int l=0;
        int r=0;
        int n=s.size();
        int cnt=0;
        int start=-1;
        int mini=INT_MAX;
        while(l<=r && r<n){
            if(mp[s[r]]>0){
                cnt++;
                
            }
            mp[s[r]]--;
            while(cnt==m  && l<=r){
                if((r-l+1)<mini){
                    mini=r-l+1;
                    start=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                
                l++;
            }
            r++;
            
        }
        if(start==-1) return "";
        return s.substr(start,mini);
    }
};