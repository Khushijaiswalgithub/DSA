/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* newNode = new Node(data);

    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* curr = head;

    
    if (data < head->data) {
        // Find last node
        while (curr->next != head) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (curr->next != head && curr->next->data < data) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
    }
};