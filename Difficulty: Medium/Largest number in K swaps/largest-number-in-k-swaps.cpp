//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
    void findMaximum(string &s, int k, string &maxNum, int index) {
    if (k == 0) return;

    int n = s.size();
    char maxChar = s[index];

    for (int i = index + 1; i < n; i++) {
        if (s[i] > maxChar) {
            maxChar = s[i];
        }
    }

    if (maxChar != s[index]) k--;

    for (int i = index; i < n; i++) {
        if (s[i] == maxChar) {
            swap(s[index], s[i]);
            if (s.compare(maxNum) > 0) {
                maxNum = s;
            }
            findMaximum(s, k, maxNum, index + 1);
            swap(s[index], s[i]); // backtrack
        }
    }
}

string findMaximumNum(string &s, int k) {
    string maxNum = s;
    findMaximum(s, k, maxNum, 0);
    return maxNum;
}

    // string findMaximumNum(string& s, int k) {
    //     // code here.
    // }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends