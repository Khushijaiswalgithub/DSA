// User function template for C++
class Solution {
  public:
    int lower(vector<int>arr,int x){
        int l=0;
        int r=arr.size();
        while(l<r){
            int mid=(l+r)/2;
            if(arr[mid]>=x){
                r--;
            }
            else{
                l++;
            }
        }
        return l;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int ans=-1;
        int maxi=-1;
        for(int i=0;i<n;i++){
            int l=lower(arr[i],1);
            if(maxi<(m-l-1)){
                maxi=m-l-1;
                ans=i;
            }
        }
        return ans;
    }
};