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
};
*/

class Solution {
  public:
    Node* solve(int prestart,int poststart,int preend,vector<int> &pre, vector<int> &post){
        if(prestart>preend) return NULL;
        Node* root=new Node(pre[prestart]);
        if(prestart==preend){
            return root;
        }
        int j=poststart;
        int next=pre[prestart+1];
        while(post[j]!=next){
            j++;
        }
        int num=j-poststart+1;
        root->left=solve(prestart+1,poststart,prestart+num,pre,post);
        root->right=solve(prestart+num+1,j+1,preend,pre,post);
        return root;
        
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        int preend=pre.size()-1;
        return solve(0,0,preend,pre,post);
    }
};