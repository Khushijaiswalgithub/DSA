class Solution {
  public:
  #define MOD 1000000007
#define BASE 26

    vector<int> search(string &pat, string &txt) {
        // code here.
        int n = txt.size(), m = pat.size();
    if (m > n) return {};

    vector<int> result;

    long long patternHash = 0, textHash = 0, power = 1;

    // Precompute the highest power of BASE^(m-1)
    for (int i = 0; i < m - 1; i++)
        power = (power * BASE) % MOD;

    // Compute hash of pattern and first window of text
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * BASE + (pat[i] - 'a')) % MOD;
        textHash = (textHash * BASE + (txt[i] - 'a')) % MOD;
    }

    // Slide the window over text
    for (int i = 0; i <= n - m; i++) {
        // If the hashes match, do a direct comparison to avoid false positives
        if (patternHash == textHash && txt.substr(i, m) == pat)
            result.push_back(i + 1); // 1-based indexing

        // Roll the hash
        if (i < n - m) {
            textHash = (textHash - (txt[i] - 'a') * power % MOD + MOD) % MOD;
            textHash = (textHash * BASE + (txt[i + m] - 'a')) % MOD;
        }
    }

    return result;
    }
};