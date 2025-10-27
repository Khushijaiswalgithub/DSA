class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=arr1.size();
        int m=arr2.size();
        for(int i=0;i<min(k,n);i++){
            for(int j=0;j<min(k,m);j++){
                int sum=arr1[i]+arr2[j];
                pq.push({sum,{arr1[i],arr2[j]}});
            }
        }
        int x=0;
        vector<vector<int>>ans;
        while(!pq.empty() && x!=k){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
            x++;
            
        }
        return ans;
    }
};
