class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr.push_back(arr[i]);
        }
        stack<int>st;
        vector<int>res(n,-1);
        
        for(int i=2*n-1;i>=0;i--){
            int curr=arr[i];
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            if(i<n && !st.empty()){
                res[i]=st.top();
            }
            st.push(curr);
        }
        return res;
    }
};