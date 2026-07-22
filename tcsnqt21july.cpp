#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* findMiddle(Node* head) {
    if (head == NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        return 0;
    }
    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }
    Node* mid = findMiddle(head);
    if (mid != NULL)
        cout << mid->data;
    return 0;
}