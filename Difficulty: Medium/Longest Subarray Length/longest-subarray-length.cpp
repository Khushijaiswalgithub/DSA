class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        // code here
       int n=arr.size();
       stack<int>st;
       vector<int>l(n,-1),r(n,n);
       for(int i=0;i<n;i++){
           while(!st.empty() && arr[st.top()]<=arr[i]){
               st.pop();
           }
           if(!st.empty()){
               l[i]=st.top();
           }
           st.push(i);
       }
       while(!st.empty()) st.pop();
       for(int i=n-1;i>=0;i--){
           while(!st.empty() && arr[st.top()]<=arr[i]){
               st.pop();
           }
           if(!st.empty()){
               r[i]=st.top();
           }
           st.push(i);
       }
       int maxi=0;
       for(int i=0;i<n;i++){
           int len=r[i]-l[i]-1;
           if(arr[i]<=len){
               maxi=max(maxi,len);
           }
       }
       return maxi;
    }
};