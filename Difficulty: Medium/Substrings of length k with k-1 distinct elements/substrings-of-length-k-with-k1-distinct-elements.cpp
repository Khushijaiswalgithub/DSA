class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n=s.size();
        if(k>n) return 0;
        int c=0;
        int l=0;
        unordered_map<char,int>mp;
        int r=k-1;
        for(int i=l;i<=r;i++){
            mp[s[i]]++;
        }
        while(r<n && l<r){
            if(mp.size()==k-1){
                c++;
            }
            
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;
            r++;
            mp[s[r]]++;
        }
        return c;
    }
};