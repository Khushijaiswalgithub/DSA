class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int>st;
        vector<int>l(n,-1),r(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) l[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) r[i]=st.top();
            st.push(i);
        }
        vector<int>ans(n,INT_MIN);
        for (int i = 0; i < n; i++) {
        int len = r[i] - l[i] - 1;  
        ans[len - 1] = max(ans[len - 1], arr[i]);
    }


    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    return ans;
    }
};