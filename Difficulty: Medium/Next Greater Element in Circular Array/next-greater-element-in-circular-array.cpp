class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            int curr=i%n;
            while(!st.empty() && arr[st.top()]<=arr[curr]){
                st.pop();
            }
            if(i<n){if(!st.empty()) ans[i]=arr[st.top()];}
            st.push(i%n);
        }
        
        return ans;
    }
};