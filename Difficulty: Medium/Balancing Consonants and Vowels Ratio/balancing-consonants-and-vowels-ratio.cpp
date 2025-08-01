class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
        string s="";
        for(auto it:arr){
            s+=it;
        }
        int n=s.size();
        vector<int>pre(n);
        if(s[0]=='a'  || s[0]=='e' || s[0]=='i'|| s[0]=='o' || s[0]=='u'){
            pre[0]=1;
        }
        else{
            pre[0]=-1;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o' || s[i]=='u'){
                pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=pre[i-1]-1;
            }
        }
        map<int,int>mp;
        mp[0]=1;
        int c=0;
        int ind=0;
        for(auto it:arr){
            int x=pre[it.size()+ind-1];
            if(mp.find(x)!=mp.end()){
                c+=mp[x];
            }
            mp[x]++;
            ind+=it.size();
        }
    
        return c;
        
    }
};