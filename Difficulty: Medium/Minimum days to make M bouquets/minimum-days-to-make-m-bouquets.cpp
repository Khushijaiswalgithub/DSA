class Solution {
  public:
    bool valid(vector<int>& arr, int mid, int m,int n,int k){
        int cnt=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=mid){
                cnt++;
            }
            else{
                b+=(cnt/k);
                cnt=0;
            }
        }
        b+=(cnt/k);
        return b>=m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n=arr.size();
        if(n<(k*m)) return -1;
        int l=*min_element(arr.begin(),arr.end());
        int h=*max_element(arr.begin(),arr.end());
        while(l<=h){
            int mid=(l+h)/2;
            
            if(valid(arr,mid,m,n,k)){
                h=mid-1;
                
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};