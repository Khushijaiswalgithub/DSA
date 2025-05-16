//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  struct Element {
    int value;
    int listIndex;
    int elementIndex;

    bool operator>(const Element &other) const {
        return value > other.value;
    }
};

vector<int> findSmallestRange(vector<vector<int>>& arr) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    int maxInHeap = INT_MIN;
    int k = arr.size();

    for (int i = 0; i < k; i++) {
        minHeap.push({arr[i][0], i, 0});
        maxInHeap = max(maxInHeap, arr[i][0]);
    }

    int rangeStart = 0, rangeEnd = INT_MAX;

    while (true) {
        Element minElement = minHeap.top();
        minHeap.pop();

        int currentRange = maxInHeap - minElement.value;
        if (currentRange < rangeEnd - rangeStart) {
            rangeStart = minElement.value;
            rangeEnd = maxInHeap;
        }

        if (minElement.elementIndex + 1 < arr[minElement.listIndex].size()) {
            int nextValue = arr[minElement.listIndex][minElement.elementIndex + 1];
            minHeap.push({nextValue, minElement.listIndex, minElement.elementIndex + 1});
            maxInHeap = max(maxInHeap, nextValue);
        } else {
            break;
        }
    }

    return vector<int>{rangeStart, rangeEnd};
}

    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends