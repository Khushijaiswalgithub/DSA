//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        
        int sign1 = 1, sign2 = 1;
    
    // Handle negative numbers
    if (s1[0] == '-') {
        sign1 = -1;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        sign2 = -1;
        s2 = s2.substr(1);
    }

    
    if (s1 == "0" || s2 == "0") return "0";

    int n = s1.size();
    int m = s2.size();
    vector<int> res(n + m, 0);

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            res[i + j] += mul;
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
        }
    }

    string ans = "";
    int i = n + m -1;
    while (i >= 0 && res[i] == 0) i--;
    if (i == -1) return "0";
    while (i >= 0) {
        ans += (res[i] + '0');
        i--;
    }
    if (sign1 * sign2 == -1) {
        ans = "-" + ans;
    }

    return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends