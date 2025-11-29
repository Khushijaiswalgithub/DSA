class Solution {
  public:
    int largestPowerOf2(int n) {
    int x = 0;
    while ((1 << (x + 1)) <= n) x++;
    return x;
}

int countSetBits(int n) {
    if (n == 0) return 0;

    int x = largestPowerOf2(n);     // highest power of 2 <= n
    int p = 1 << x;                 // 2^x

    // 1) Count bits from 1 to (2^x - 1)
    int bitsBefore = x * (p >> 1);

    // 2) Count MSB bits from 2^x to n
    int msbBits = n - p + 1;

    // 3) Count remaining bits recursively
    int rest = countSetBits(n - p);

    return bitsBefore + msbBits + rest;
}
};
