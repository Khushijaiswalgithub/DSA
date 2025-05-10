//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
    int maxLength = 0;
    int balance = 0;
    unordered_map<int, int> balanceIndex;
    balanceIndex[0] = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > k) {
            balance++;
        } else {
            balance--;
        }

        if (balance > 0) {
            maxLength = i + 1;
        } else if (balanceIndex.find(balance - 1) != balanceIndex.end()) {
            maxLength = max(maxLength, i - balanceIndex[balance - 1]);
        }

        if (balanceIndex.find(balance) == balanceIndex.end()) {
            balanceIndex[balance] = i;
        }
    }

    return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends