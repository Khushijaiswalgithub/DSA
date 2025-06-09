/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool f(Node *root,int min,int max){
        if(!root) return 0;
        if(!root->left && !root->right){
            if(root->data-min==1 && max-root->data==1){
                return 1;
            }
            else{
                return 0;
            }
        }
        return f(root->left,min,root->data) || f(root->right,root->data,max);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        return f(root,0,INT_MAX);
    }
};