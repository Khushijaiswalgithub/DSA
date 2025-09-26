class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        int n=dq.size();
        if(type==1) k=n-k;
        k=k%n;
        while(k--){
            int x=dq.front();
            dq.pop_front();
            dq.push_back(x);
            
        }
    }
};