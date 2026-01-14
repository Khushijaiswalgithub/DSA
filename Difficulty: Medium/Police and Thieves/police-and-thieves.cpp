class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        vector<int>p;
        vector<int>t;
        for(int i=0;i<n;i++){
            if(arr[i]=='P') p.push_back(i);
            else if(arr[i]=='T')t.push_back(i);
        }
        int i=0;
        int j=0;
        int c=0;
        while(i<p.size() && j<t.size()){
            if(abs(p[i]-t[j])<=k){
                c++;
                i++;
                j++;
            }
            else if(p[i]<t[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return c;
    }
};