/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        if(root==NULL) return root;
        root->left=removekeys(root->left,l,r);
        root->right=removekeys(root->right,l,r);
        
        if(root->data<l){
            Node* rdata=root->right;
            delete root;
            return rdata;
        }
        if(root->data>r){
            Node* ldata=root->left;
            delete root;
            return ldata;
        }
        return root;
    }
};