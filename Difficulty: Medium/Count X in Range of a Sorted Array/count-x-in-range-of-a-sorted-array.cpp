class Solution {
  public:
    int lower(vector<int>&arr,int l,int h,int x){
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]>=x){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    int upper(vector<int>&arr,int l,int h,int x){
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]>x){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int>ans;
        for(auto it:queries){
            ans.push_back(upper(arr,it[0],it[1],it[2])-lower(arr,it[0],it[1],it[2]));
        }
        return ans;
        
    }
};