class Solution {
  public:
   int f(vector<int>&arr,int n){
       int c=0;
       for(int i=0;i<arr.size();i++){
           
           c += (arr[i] + n - 1) / n;
           
       }
       return c;
       
   }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int l=1;
        int r=*max_element(arr.begin(), arr.end());
        int ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(arr,mid)<=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
