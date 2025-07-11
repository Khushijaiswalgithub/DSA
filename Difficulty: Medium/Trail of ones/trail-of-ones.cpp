class Solution {
  public:
    int countConsec(int n) {
        // code here
       if (n <= 2) return 1;

    long long a = 0, b = 1;
    long long ans = 1;

    for (int i = 3; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
        ans = ans * 2 + c;
    }

    return ans;
    }
};