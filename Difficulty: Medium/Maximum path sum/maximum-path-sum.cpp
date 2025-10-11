/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int findMaxSum(Node *root) {
        // code here
        int maxi=INT_MIN;
        maxpath(root,maxi);
        return maxi;
        
    }
    int maxpath(Node *root,int &maxi){
        if(root==NULL) return 0;
        int l=max(0,maxpath(root->left,maxi));
        int r=max(0,maxpath(root->right,maxi));
        maxi=max(maxi,l+r+root->data);
        return max(l,r)+root->data;
        
    }
};