class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        vector<int>ans;
        vector<int>odd;
        vector<int>even;
        for(auto it:arr){
            if(it%2==0){
                even.push_back(it);
            }
            else{
                odd.push_back(it);
            }
        }
        sort(odd.rbegin(),odd.rend());
        for(int i=0;i<odd.size();i++){
           arr[i]=odd[i];
        }
        sort(even.begin(),even.end());
        int j=odd.size();
        for(int i=0;i<even.size();i++){
            arr[j]=even[i];
            j++;
        }
        
    
    }
};