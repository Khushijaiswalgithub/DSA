//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
            
        }
        int maxi=0;
        int c=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,mp[s[i]]);
            if(maxi==i){
                c++;
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends