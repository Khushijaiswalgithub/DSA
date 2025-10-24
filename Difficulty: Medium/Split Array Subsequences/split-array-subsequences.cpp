class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        using pii = pair<int, int>;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int num:arr){
            while(!pq.empty() && pq.top().first+1<num){
                if(pq.top().second<k) return false;
                pq.pop();
            }
            if(!pq.empty() && pq.top().first+1==num){
               auto [last, len] = pq.top();
               pq.pop();
               pq.push({num, len + 1});
            } else {
        
              pq.push({num, 1});
            
            }
        }
        while (!pq.empty()) {
        if (pq.top().second < k) return false;
        pq.pop();
    }

    return true;
        return true;
    }
};
