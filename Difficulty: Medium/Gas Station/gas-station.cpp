class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n=gas.size();
        int t=0;
        int curr=0;
        int s=0;
        for(int i=0;i<n;i++){
            t+=gas[i]-cost[i];
            curr+=gas[i]-cost[i];
            if(curr<0){
                s=i+1;
                curr=0;
            }
            
        }
        return (t>=0)?s:-1;
    }
};