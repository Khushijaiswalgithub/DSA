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
    void f(Node* root,int tar,int k,priority_queue<pair<int,int>>&pq){
        if(root==NULL) return;
        f(root->left,tar,k,pq);
        pq.push({abs(root->data-tar),root->data});
        while(pq.size()>k){
            pq.pop();
        }
        f(root->right,tar,k,pq);
        
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        priority_queue<pair<int,int>>pq;
        f(root,target,k,pq);
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};