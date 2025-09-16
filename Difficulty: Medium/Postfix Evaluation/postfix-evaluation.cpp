class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int>st;
        for(auto it:arr){
            if(it=="*" || it=="-" || it=="+" || it=="^" || it=="/"){
                int y=st.top();
                st.pop();
                int x=st.top();
                st.pop();
                if(it=="+")st.push(x+y);
                if(it=="-")st.push(x-y);
                if(it=="*")st.push(x*y);
                if(it=="/"){
                    if ((x < 0) ^ (y< 0) && x % y != 0)
                    st.push(x / y - 1); 
                else
                    st.push(x /y);
                }
                if(it=="^")st.push((int)pow(x,y));
                
                
            }
            else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};