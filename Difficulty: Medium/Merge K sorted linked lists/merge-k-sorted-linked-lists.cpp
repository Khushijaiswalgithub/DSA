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
    struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& arr) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto list : arr) {
        if (list) pq.push(list);
    }

    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (!pq.empty()) {
        Node* temp = pq.top();
        pq.pop();

        tail->next = temp;
        tail = tail->next;

        if (temp->next) pq.push(temp->next);
    }

    return dummy->next;
}

};