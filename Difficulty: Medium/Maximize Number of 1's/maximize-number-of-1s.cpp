class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int l=0;
        int r=0;
        int c=0;
        int maxi=0;
        while(l<=r && r<n){
            if(arr[r]==0) c++;
            while(c>k){
                if(arr[l]==0) c--;
                l++;
                
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
