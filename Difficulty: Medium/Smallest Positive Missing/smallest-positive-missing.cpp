class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        
        unordered_set<int>st;
        int n=arr.size();
        int s=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
            st.insert(arr[i]);
            }
            
        }
        for(int i=1;i<=(n+1);i++){
            if(st.find(i)==st.end()){
                return i;
            }
        }
        return 1;
        
        
    }
};