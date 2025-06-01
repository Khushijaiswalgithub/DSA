class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        unordered_set<int>st;
        int n=mat1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                st.insert(mat1[i][j]);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int k=mat2[i][j];
                if(st.count(x-k)){
                    c++;
                }
            }
        }
        return c;
        
    }
};