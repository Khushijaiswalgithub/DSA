//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_set<int>st;
        int n=str.size();
        for(int i=0;i<n;i++){
            st.insert(str[i]);
        }
        int c=st.size();
        int i=0;
        int j=0;
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        while(j<n){
            mp[str[j]]++;
            if(mp.size()>=c){
                while(mp[str[i]]>1){
                    mp[str[i]]--;
                    i++;
                }
                ans=min(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends