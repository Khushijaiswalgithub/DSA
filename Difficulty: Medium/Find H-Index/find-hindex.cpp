class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.begin(),citations.end());
        int n=citations.size();
        int h = 0;

    for (int i = 0; i < n; i++) {           
        int papersWithAtLeastCitations = n - i; 
        h = max(h, min(citations[i], papersWithAtLeastCitations)); 
    }
    return h;
    }
};