/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int f(Node* root,int &mov){
        if(root==NULL) return 0;
        int l=f(root->left,mov);
        int r=f(root->right,mov);
        mov+=abs(l)+abs(r);
        return (l+r+root->data)-1;
    }
    int distCandy(Node* root) {
        // code here
        int mov=0;
        f(root,mov);
        return mov;
        
    }
};