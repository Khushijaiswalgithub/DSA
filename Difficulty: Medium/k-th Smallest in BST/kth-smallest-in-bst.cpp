/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node *root,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    int kthSmallest(Node *root, int k) {
        // code here
        vector<int>ans;
        inorder(root,ans);
        if(ans.size()<k) return -1;
        
        return ans[k-1];
    }
};