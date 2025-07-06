class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        int n=a.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>>st;
        pq.push({a[0]+b[0],{0,0}});
        st.insert({0,0});
        vector<int>result;
        while(result.size()<k){
            auto top=pq.top();
            pq.pop();
            int sum=top.first;
            int i=top.second.first;
            int j=top.second.second;
            result.push_back(sum);
            
            if(j+1<n && st.find({i,j+1})==st.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
            if(i+1<n && st.find({i+1,j})==st.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                st.insert({i+1,j});
            }
            
        }
        return result;
    }
};