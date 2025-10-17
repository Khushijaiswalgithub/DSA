/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
  int sum=0;
    void transformTree(Node *root) {
        // code here
        if (!root) return;
        transformTree(root->right);
        sum += root->data;
        root->data = sum - root->data;

        transformTree(root->left);
    }
};