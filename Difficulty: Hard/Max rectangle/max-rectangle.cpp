class Solution {
  public:
    int histo(vector<int>arr){
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
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int w=r[i]-l[i]-1;
            int area=arr[i]*w;
            maxi=max(maxi,area);
            
        }
        return maxi;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<int>arr(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (mat[i][j] == 0) arr[j] = 0;
                else arr[j] += 1;
                
            }
            maxi=max(maxi,histo(arr));
        }
        return maxi;
        
    }
};