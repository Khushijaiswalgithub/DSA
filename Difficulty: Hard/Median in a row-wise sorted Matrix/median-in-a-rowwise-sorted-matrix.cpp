class Solution {
  public:
    int upper(vector<int>arr,int x,int m){
        int l=0;
        int r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]<=x){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
    int f(vector<vector<int>> &mat,int mid,int n,int m){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upper(mat[i],mid,m);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int l=INT_MAX;
        int h=INT_MIN;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            l=min(l,mat[i][0]);
            h=max(h,mat[i][m-1]);
        }
        int req=(n*m)/2;
        while(l<=h){
            int mid=(l+h)/2;
            int s=f(mat,mid,n,m);
            if(s<=req) l=mid+1;
            else h=mid-1;
        }
        return l;
    }
};
