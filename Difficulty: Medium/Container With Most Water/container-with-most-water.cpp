class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0;
        int r=n-1;
        int maxi=0;
        while(l<r){
            int a=min(arr[l],arr[r])*(r-l);
            
            maxi=max(a,maxi);
            if(arr[l]>arr[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxi;

    }
};