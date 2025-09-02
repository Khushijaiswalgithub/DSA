/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int len(Node* head){
        Node* temp=head;
        int c=0;
        while(temp){
            c++;
            temp=temp->next;
        }
        return c;
    }
    Node* swapKth(Node* head, int k) {
        // code here
        int l=len(head);
        if(l<k) return head;
        if(l==1) return head;
        int n=1;
        Node* temp=head;
        int d1=-1;
        int d2=-1;
        while(temp){
            if(n==k) d1=temp->data;
            if(n==l-k+1) d2=temp->data;
            n++;
            
            temp=temp->next;
            
        }
        temp=head;
        n=1;
        while(temp){
            if(n==k) temp->data=d2;
            if(n==l-k+1) temp->data=d1;
            n++;
            
            temp=temp->next;
            
        }
        return head;
        
        
        
        
        
    }
};