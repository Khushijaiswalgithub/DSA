class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int ans=0;
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(mp[s[i]]>=mp[s[i+1]]){
                ans+=mp[s[i]];
            }
            else{
                ans-=mp[s[i]];
            }
        }
        ans+=mp[s[n-1]];
        return ans;
    }
};