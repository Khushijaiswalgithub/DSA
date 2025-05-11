//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
    vector<int> presum(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> minh;
    
    for (int i = 0; i < n; i++) {
        presum[i + 1] = presum[i] + arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {  // Fixed the inner loop to increment j
            int sum = presum[j] - presum[i];
            if (minh.size() < k) {
                minh.push(sum);
            } else if (sum > minh.top()) {
                minh.pop();
                minh.push(sum);
            }
        }
    }

    return minh.top();
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends