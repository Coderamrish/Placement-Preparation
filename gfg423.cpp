/*
Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.

Examples:

Input: LinkedList = 12->15->10->11->5->6->2->3
Output: 15->11->6->3

Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. So, after deleting them, the linked list would like be 15, 11, 6, 3.
Input: LinkedList = 10->20->30->40->50->60
Output: 60

Explanation: All the nodes except the last node has a greater value node on its right, so all the nodes except the last node must be removed.
Constraints:
1 ≤ size of linked list ≤ 106
1 ≤ element of linked list ≤ 106

Note: Try to solve the problem without using any extra space.
*/
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
Node* compute(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    head = reverseList(head);
    Node* curr = head;
    Node* maxNode = head;
    while (curr && curr->next) {
        if (curr->next->data < maxNode->data) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
            maxNode = curr;
        }
    }
    return reverseList(head);
}
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    if (n <= 0) return 0;
    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }
    head = compute(head);
    printList(head);
    return 0;
}