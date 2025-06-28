class Solution {
  public:
    int f(vector<int>& b,int n){
        int l=0;
        int r=b.size()-1;
        int ans=-1;
        while(r>=l){
            int mid=(l+r)/2;
            if(b[mid]>n){
                r=mid-1;
            }
            else{
                ans=mid;
                l=mid+1;
                
            }
        }
        return ans+1;
    }
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(),b.end());
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            ans.push_back(f(b,a[i]));
        }
        return ans;
    }
};