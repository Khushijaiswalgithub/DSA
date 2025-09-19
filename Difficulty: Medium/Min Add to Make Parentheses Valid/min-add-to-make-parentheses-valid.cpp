class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char>st;
        
        for(char ch:s){
            if(!st.empty() &&st.top()=='(' && ch==')'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        return st.size();
    }
};