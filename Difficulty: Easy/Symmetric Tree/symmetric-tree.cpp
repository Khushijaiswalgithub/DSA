/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool f(Node* root1,Node *root2){
        if(root1==NULL && root2==NULL) return true;
        if (root1 == NULL || root2 == NULL) return false;

        if(root1->data==root2->data){
           return f(root1->left,root2->right) && f(root1->right,root2->left);
        }
        return false;
        
        
        
    }
    bool isSymmetric(Node* root) {
        // Code here
        if (root == NULL) return true;
        return f(root->left,root->right);
        
        
    }
};