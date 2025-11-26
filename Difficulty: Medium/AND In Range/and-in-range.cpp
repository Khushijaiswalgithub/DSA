class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        while (l < r) {
            r = r & (r - 1); 
        }
        return r;
    }
};
