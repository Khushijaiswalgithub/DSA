class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int l=0;
        int n=arr.size();
        int h=n-1;
        
        while(l<=h){
            int mid=(l+h)/2;
            int mis=arr[mid]-(mid+1);
            if(mis<k) l=mid+1;
            else h=mid-1;
            
        }
        return l+k;
    }
};