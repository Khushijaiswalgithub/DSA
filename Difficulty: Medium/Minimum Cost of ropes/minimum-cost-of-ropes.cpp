class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:arr){
            pq.push(it);
        }
        int cost=0;
        while(pq.size()!=1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            pq.push(x+y);
            cost+=x+y;
        }
        
        return cost;
    }
};