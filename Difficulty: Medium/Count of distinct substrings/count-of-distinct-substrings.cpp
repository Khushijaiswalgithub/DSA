class Solution {
  public:
  vector<int> buildSA(string s) {
    int n = s.size();
    vector<int> sa(n), rnk(n), tmp(n);
    
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rnk[i] = s[i];
    }
    
    for (int k = 1;; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
            int ri = (i + k < n) ? rnk[i + k] : -1;
            int rj = (j + k < n) ? rnk[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);
        
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        
        rnk = tmp;
        if (rnk[sa[n - 1]] == n - 1) break;
    }
    return sa;
}
vector<int> buildLCP(string s, vector<int> &sa) {
    int n = s.size();
    vector<int> rnk(n), lcp(n);
    
    for (int i = 0; i < n; i++)
        rnk[sa[i]] = i;
    
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rnk[i] > 0) {
            int j = sa[rnk[i] - 1];
            while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
            lcp[rnk[i]] = h;
            if (h > 0) h--;
        }
    }
    return lcp;
}


    int countSubs(string& s) {
        // code here
        int n = s.size();
    auto sa = buildSA(s);
    auto lcp = buildLCP(s, sa);

    long long total = 1LL * n * (n + 1) / 2;
    long long repeated = 0;

    for (int i = 0; i < n; i++)
        repeated += lcp[i];

    return total - repeated;

    }
};