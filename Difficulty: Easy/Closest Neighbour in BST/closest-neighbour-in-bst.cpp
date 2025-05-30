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
    
    int findMaxFork(Node* root, int k) {
        // code here
        Node *temp=root;
        int ans=-1;
        while(temp!=NULL){
        if(temp->data<=k){
            ans=temp->data;
            temp=temp->right;
        
        }
        else{
            temp=temp->left;
        }
        }
        return ans;
        
    }
};