class Solution {
  public:
   int f(string& s, int k){
       int mp[26]={0};
       int c=0;
       int l=0,r=0;
       int d=0;
       while(r<s.size()){
           if(mp[s[r]-'a']==0){
               d++;
           }
           mp[s[r]-'a']++;
           while(d>k ){
               mp[s[l]-'a']--;
              if(mp[s[l]-'a']==0){
                 d--;
              }
               l++;
           }
           c+=r-l+1;
           r++;
       }
       return c;
       
   }
    int countSubstr(string& s, int k) {
        // code here.
        return f(s,k)-f(s,k-1);
    }
};