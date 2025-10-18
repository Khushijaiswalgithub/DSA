/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& ans) {
    if (!root) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

int findMedian(Node* root) {
    if (root == NULL) return -1;
    
    vector<int> ans;
    inorder(root, ans);
    int n = ans.size();
    int mid=n/2;
    if (n % 2 == 0) {

        return ans[mid-1];
    } else {
    
        return ans[(n-1)/2];
    }
}
};