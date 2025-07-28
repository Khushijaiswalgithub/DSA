class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int maxi=0;
        int op=0;
        for(int i=0;i<n;i++){
            int rsum=0;
            for(int j=0;j<n;j++){
                rsum+=mat[i][j];
            }
            maxi=max(maxi,rsum);
        }
        for(int j=0;j<n;j++){
            int csum=0;
            for(int i=0;i<n;i++){
                csum+=mat[i][j];
            }
            maxi=max(maxi,csum);
        }
        for(int i=0;i<n;i++){
            int rsum=0;
            for(int j=0;j<n;j++){
                rsum+=mat[i][j];
            }
            op+=maxi-rsum;
        }
        return op;
    }
};