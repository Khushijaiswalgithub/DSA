class Solution {
  public:
    string decodedString(string &s) {
        // code here
        
        stack<string>st;
        stack<int>stnum;
        
        string curr="";
        int num=0;
        for(char ch:s){
            if (isdigit(ch)) {
               num = num * 10 + (ch - '0'); 
            }
            else if(ch=='['){
                st.push(curr);
                stnum.push(num);
                num=0;
                curr="";
            }
            else if(ch==']'){
                string t=curr;
                curr=st.top();
                st.pop();
                int n=stnum.top();
                stnum.pop();
                while(n--){
                    curr+=t;
                }
                
            }
            
            else{
                curr.push_back(ch);
            }
        }
        
        return curr;
    }
};