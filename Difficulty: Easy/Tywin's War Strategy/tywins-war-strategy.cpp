class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int x=0;
            if(arr[i]%k!=0){
             x=k-(arr[i]%k);
            }
            ans.push_back(x);
            
        }
        sort(ans.begin(),ans.end()); 
        int j=n/2;
        if(n%2!=0) j+=1;
        int res=0;
        for(int i=0;i<j;i++){
            res+=ans[i];
        }
        return res;
    }
};