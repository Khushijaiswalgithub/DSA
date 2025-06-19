class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string s1=s;
        vector<char>v1;
        vector<char>v2;
        for(char ch:s){
            if(isupper(ch)){
                v1.push_back(ch);
            }
            else{
                v2.push_back(ch);
            }
            
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(isupper(s[i])){
                s1[i]=v1[x];
                x++;
            }
            else{
                s1[i]=v2[y];
                y++;
            }
        }
        return s1;
    }
};