class Solution {
  public:
  int m;
   int peak(vector<int>&arr){
       int l=0;
       int h=m-1;
       while(l<h){
           int mid=(l+h)/2;
           if(arr[mid]<arr[mid+1]){
               l=mid+1;
           }
           else{
               h=mid;
           }
       }
       return l;
   }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        m=mat[0].size();
        int l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            int maxi=0;
            
        
        for(int i=0;i<n;i++){
            if(mat[i][mid]>mat[maxi][mid]){
                maxi=i;
            }
        }
        bool left=(mid==0) || mat[maxi][mid]>=mat[maxi][mid-1];
        bool right=(mid==m-1)|| mat[maxi][mid]>=mat[maxi][mid+1];
        if(left && right){
            return {maxi,mid};
        } 
        else if(mid>0 && mat[maxi][mid-1]>=mat[maxi][mid]){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
                
            
        }
    
        return {-1,-1};
    }
};
