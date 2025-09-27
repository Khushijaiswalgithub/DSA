class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int f=0;
        int c=0;
        vector<bool> isflipped(n,false);
        
        for(int i=0;i<n;i++){
            if(i>=k && isflipped[i-k]==true){
                f--;
            }
            if((arr[i] + f) % 2 == 0){
                if((i+k) >n){
                    return -1;
                }
                f++;
                c++;
                isflipped[i]=true;
            }
        }
        return c;
    }
};