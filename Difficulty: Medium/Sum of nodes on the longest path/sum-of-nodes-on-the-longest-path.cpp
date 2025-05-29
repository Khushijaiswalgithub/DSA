/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:  
    void f(Node *root,int &mxc,int c,int sum,int &ans){
        if(!root){
            if(c>mxc){
                mxc=c;
                ans=sum;
            }
            else if(c==mxc){
                ans=max(ans,sum);
            }
            return;
        }
        sum+=root->data;
        c++;
        f(root->left,mxc,c,sum,ans);
        f(root->right,mxc,c,sum,ans);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int ans=INT_MIN;
        int sum=0;
        int c=0;
        int mxc=0;
        f(root,mxc,c,sum,ans);
        return ans;
        
    }
};