class Solution {
  public:
    bool f(vector<int>& heights, vector<int>& cost,int t){
        int m=0;
        int n=0;
        for(int i=0;i<heights.size();i++){
            m+=abs(heights[i]-t)*cost[i];
            n+=abs(heights[i]-t-1)*cost[i];
            
        }
        return n>m;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int l=*min_element(heights.begin(),heights.end());
        int r=*max_element(heights.begin(),heights.end());
        int target=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(heights,cost,mid)){
                target=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans+=abs(heights[i]-target)*cost[i];
        }
        return ans;
        
        
    }
};
