class Solution {
  public:
    
    int sumSubstrings(string &s) {
        // code here
        int n=s.size();
        long long sum=0;
        long long f=1;
        for(int i=n-1;i>=0;i--){
            sum+=(s[i]-'0')*(i+1)*f;
            f=f*10+1;
            
        }
        return sum;
        
    }
};