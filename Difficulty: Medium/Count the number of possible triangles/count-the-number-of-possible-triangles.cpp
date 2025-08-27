class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int c=0;
        for(int k=n-1;k>=2;k--){
        int i=0;
        int j=k-1;
        
        
        while(i<j){
            if((arr[i]+arr[j])>arr[k]){
            c += (j - i);
            j--;
            
            }
            else{
                i++;
            }
        }
        }
        return c;
    }
};
