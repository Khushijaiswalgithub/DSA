class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int f=0;
        int t=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==5) f++;
            else if(arr[i]==10){
                if(f)f--,t++;
                else return false;
            }
            else{
                if(f&&t){
                    f--;
                    t--;
                    
                }
                else if(f>=3){
                    f-=3;
                }
                else{
                    return false;
                }
            }
            
        }
        return true;
    }
};