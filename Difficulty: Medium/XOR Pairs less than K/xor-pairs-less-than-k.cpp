class Solution {
public:

    struct TrieNode {
        TrieNode* child[2];
        int count;
        TrieNode() {
            child[0] = child[1] = NULL;
            count = 0;
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void insert(int num) {
            TrieNode* node = root;
            for (int i = 15; i >= 0; i--) { // Because arr[i] <= 5*10^4
                int bit = (num >> i) & 1;
                if (!node->child[bit])
                    node->child[bit] = new TrieNode();
                node = node->child[bit];
                node->count++;
            }
        }

        // Count numbers already in trie such that (num XOR x) < K
        int countLessXor(int num, int k) {
            TrieNode* node = root;
            int ans = 0;

            for (int i = 15; i >= 0; i--) {
                if (!node) break;

                int bitN = (num >> i) & 1;
                int bitK = (k   >> i) & 1;

                if (bitK == 1) {
                    // If k has 1 here, we can add all numbers where XOR bit = 0
                    if (node->child[bitN])
                        ans += node->child[bitN]->count;

                    node = node->child[bitN ^ 1];
                }
                else {
                    node = node->child[bitN];
                }
            }

            return ans;
        }
    };

    int cntPairs(vector<int>& arr, int k) {
        Trie t;
        int ans = 0;

        for (int x : arr) {
            ans += t.countLessXor(x, k);
            t.insert(x);
        }

        return ans;
    }
};
