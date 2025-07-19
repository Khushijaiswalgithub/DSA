class Solution {
  public:
    int fac(int n){
        if(n<=1){
            return 1;
        }
        return n*fac(n-1);
    }
    int vowelCount(string& s) {
        // code here
        unordered_map<char,int>mp;
        for(char it:s){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u'){
                mp[it]++;
            }
        }
        int n=mp.size();
        int ans=1;
        for(auto it:mp){
            ans*=it.second;
        }
        return n==0?0: ans*fac(n);
    }
};