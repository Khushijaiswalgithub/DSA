class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int mini=INT_MAX;
        int profit=0;
        int maxi=0;
        for(int i=0;i<prices.size();i++){
            if(mini!=INT_MIN){
                profit=prices[i]-mini;
                maxi=max(maxi,profit);
            }
            mini=min(mini,prices[i]);
            
        }
        return maxi;
    }
};
