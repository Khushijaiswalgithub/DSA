/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*>q;
        q.push(root);
        bool f=true;
        vector<int>ans;
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            if(f){
                ans.insert(ans.end(),level.begin(),level.end());
            }
            else{
                reverse(level.begin(),level.end());
                ans.insert(ans.end(),level.begin(),level.end());
            }
            f=!f;
        }
        return ans;
    }
};