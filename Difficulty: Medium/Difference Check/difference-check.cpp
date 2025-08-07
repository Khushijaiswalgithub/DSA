class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        vector<int>diff;
        for(auto it:arr){
            int h=stoi(it.substr(0,2));
            int m=stoi(it.substr(3,2));
            int s=stoi(it.substr(6,2));
            int sec=h*60*60+m*60+s;
            diff.push_back(sec);
            
        }
        int n=diff.size();
        int mini=INT_MAX;
        sort(diff.begin(),diff.end());
        for(int i=1;i<n;i++){
            mini=min(mini,(diff[i]-diff[i-1]));
        }
        mini=min(mini,(diff[0]+24*60*60-diff[n-1]));
        return mini;
        
    }
};
