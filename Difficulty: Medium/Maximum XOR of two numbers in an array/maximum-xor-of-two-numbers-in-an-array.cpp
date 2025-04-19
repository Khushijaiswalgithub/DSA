//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
    struct TrieNode {
        TrieNode* child[2];
        TrieNode() {
            child[0] = child[1] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            if (node->child[oppositeBit]) {
                maxXor |= (1 << i);
                node = node->child[oppositeBit];
            } else {
                node = node->child[bit];
            }
        }
        return maxXor;
    }
  public:
    int maxXor(vector<int> &arr) {
        // code here
        for (int num : arr) {
            insert(num);
        }

        int result = 0;
        for (int num : arr) {
            result = max(result, getMaxXOR(num));
        }

        return result;
    
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends