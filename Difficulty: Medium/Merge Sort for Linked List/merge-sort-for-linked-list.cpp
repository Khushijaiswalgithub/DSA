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
    Node* merge(Node* left,Node* right){
        if (!left) return right;
    if (!right) return left;

    Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
    }
    Node* getMiddle(Node* head) {
    if (!head || !head->next) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
    }
    Node* mergeSort(Node* head) {
        // code here
        if (!head || !head->next) return head;
        Node* mid=getMiddle(head);
        Node* midnext=mid->next;
        mid->next=NULL;
        Node* left = mergeSort(head);
        Node* right = mergeSort(midnext);

    
        return merge(left, right);
        
    }
};