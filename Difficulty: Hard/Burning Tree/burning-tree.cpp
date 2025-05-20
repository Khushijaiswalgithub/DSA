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
    int findmaxi(map<Node*,Node*>&mp,Node* x){
        queue<Node*>q;
        q.push(x);
        map<Node*,int>vis;
        vis[x]=1;
        int maxi=0;
        while(!q.empty()){
            int s=q.size();
            int f=0;
            for(int i=0;i<s;i++){
                
                auto node=q.front();
                q.pop();
                if(node->left && vis[node->left]!=1){
                    f=1;
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && vis[node->right]!=1){
                    f=1;
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(mp[node] && vis[mp[node]]!=1){
                    f=1;
                    vis[mp[node]]=1;
                    q.push(mp[node]);
                }
            }
            if(f) maxi++;
        }
        return maxi;
    }
    Node* bfs(Node* root,map<Node*,Node*>&mp,int target){
        queue<Node*>q;
        q.push(root);
        Node* res;
        while(!q.empty()){
            Node * node=q.front();
            if(node->data==target) res=node;
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*>mp;
        Node * x=bfs(root,mp,target);
        int maxi=findmaxi(mp,x);
        return maxi;
    }
};