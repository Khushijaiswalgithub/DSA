class Solution {
  public:
   int f(vector<int> &arr, int mid){
       int s=1;
       int p=0;
       for(int i=0;i<arr.size();i++){
           if(p+arr[i]<=mid){
               p+=arr[i];
           }
           else{
               s++;
               p=arr[i];
           }
       }
       return s;
   }
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int n=arr.size();
        
        if(n<k) return -1;
        int l=*max_element(arr.begin(),arr.end());
        int h=accumulate(arr.begin(),arr.end(),0);
        while(l<=h){
            int mid=(l+h)/2;
            int s=f(arr,mid);
            if(s>k){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return l;
        
    }
};