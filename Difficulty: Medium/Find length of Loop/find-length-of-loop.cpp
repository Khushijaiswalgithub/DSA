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
    int countLoopLength(Node* loopNode) {
    Node* temp = loopNode;
    int length = 1;
    while (temp->next != loopNode) {
        length++;
        temp = temp->next;
    }
    return length;
}



    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        
        if (slow == fast) {
            return countLoopLength(slow);
        }
    }
    return 0; 
        
    }
};