class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        int mis=-1;
        int x=0;
        for(int i=1;i<=n;i++){
            x^=i;
        }
        vector<int>ans;
        if(x!=n)mis=x^n;
        for(int i=1;i<=n;i++){
            if(i!=mis){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
