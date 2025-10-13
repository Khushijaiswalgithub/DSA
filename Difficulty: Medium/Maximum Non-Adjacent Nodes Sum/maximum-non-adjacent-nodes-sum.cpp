/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    pair<long long, long long> solve(Node* root) {
    if (!root) return {0, 0};

    auto left = solve(root->left);
    auto right = solve(root->right);
    long long include = root->data + left.second + right.second;
    long long exclude = max(left.first, left.second) + max(right.first, right.second);

    return {include, exclude};
}
    int getMaxSum(Node *root) {
        // code here
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};