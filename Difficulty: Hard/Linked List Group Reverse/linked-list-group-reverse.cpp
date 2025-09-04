/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if (!head || k == 1) return head;

    Node* curr = head;
    Node* prevTail = NULL;  
    Node* newHead = NULL;    

    while (curr) {
        Node* grpHead = curr;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (!newHead) newHead = prev;

        if (prevTail) prevTail->next = prev;
        prevTail = grpHead;
    }

    return newHead;
    }
};