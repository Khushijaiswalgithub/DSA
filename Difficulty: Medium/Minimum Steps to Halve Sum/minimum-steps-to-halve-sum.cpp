class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        int n=arr.size();
        double t=0;
        priority_queue<double>pq;
        for(auto it:arr){
            t+=it;
            pq.push(it);
        }
        double x=t/2;
        int ans=0;
        while(t>x){
            double y=pq.top()/2;
            pq.pop();
            pq.push(y);
            ans++;
            t-=y;
            
        }
        return ans;
    }
};