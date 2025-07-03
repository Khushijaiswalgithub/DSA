class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        int l=0;
        int r=0;
        int maxi=-1;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            
             if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[l]]--;
                    if(mp[s[l]]==0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
                
            }
            if(mp.size()==k) maxi=max(maxi,r-l+1);
            r++;
            
            
            
        }
        return maxi;
    }
};