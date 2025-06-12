class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        priority_queue<pair<int, int>> maxh;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == x) continue; // Skip if equal to x

        int diff = abs(arr[i] - x);
        maxh.push({diff, -arr[i]});

        if (maxh.size() > k) {
            maxh.pop(); // Remove the farthest element
        }
    }

    // Extract results
    vector<int> ans;
    while (!maxh.empty()) {
        ans.push_back(-maxh.top().second);
        maxh.pop();
    }

    sort(ans.begin(),ans.end(), [&](int a, int b) {
        int da = abs(a - x);
        int db = abs(b - x);
        return (da < db) || (da == db && a > b);
    });  
    
    return ans;
        
    }
};