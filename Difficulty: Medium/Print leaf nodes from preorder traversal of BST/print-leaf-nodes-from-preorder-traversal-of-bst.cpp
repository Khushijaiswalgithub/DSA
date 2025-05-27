class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        stack<int>st;
        vector<int>ans;
        
        st.push(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            if(preorder[i]<st.top()) st.push(preorder[i]);
            else{
                int temp=st.top();
                int c=0;
                while(!st.empty()  && preorder[i]>st.top()){
                    st.pop();
                    c++;
                }
                st.push(preorder[i]);
                if(c>=2) ans.push_back(temp);
            }
        }
        ans.push_back(st.top());
        return ans;
    }
};