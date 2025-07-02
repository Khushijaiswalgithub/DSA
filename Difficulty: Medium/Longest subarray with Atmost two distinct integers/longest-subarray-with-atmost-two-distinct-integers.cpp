class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0;
        int r=0;
        int maxi=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[arr[r]]++;
            
             if(mp.size()>2){
                while(mp.size()>2){
                    mp[arr[l]]--;
                    if(mp[arr[l]]==0){
                        mp.erase(arr[l]);
                    }
                    l++;
                }
                
            }
            maxi=max(maxi,r-l+1);
            r++;
            
            
            
        }
        return maxi;
        
    }
};