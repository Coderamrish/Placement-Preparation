/*
Given the head of a singly linked list, sort the linked list using the Quick Sort algorithm.

Input Format:
The first line contains an integer N, representing the number of nodes.
The second line contains N space-separated integers representing the linked list.

Output Format:
Print the sorted linked list.

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ Node Value ≤ 10^9

Example:

Input:
6
4 2 1 5 3 2

Output:
1 2 2 3 4 5
*/
#include <iostream>
using namespace std;
struct Node {
    long long data;
    Node* next;
    Node(long long val) : data(val), next(nullptr) {}
};
void insertNode(Node*& head, Node*& tail, long long val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
Node* quickSortLinkedList(Node* head) {
    if (!head || !head->next) return head;
    Node* pivot = head;
    Node* curr = head->next;
    Node lessHead(0), equalHead(0), greaterHead(0);
    Node *lessTail = &lessHead, *equalTail = &equalHead, *greaterTail = &greaterHead;
    equalTail->next = pivot;
    equalTail = pivot;
    while (curr) {
        if (curr->data < pivot->data) {
            lessTail->next = curr;
            lessTail = curr;
        } else if (curr->data > pivot->data) {
            greaterTail->next = curr;
            greaterTail = curr;
        } else {
            equalTail->next = curr;
            equalTail = curr;
        }
        curr = curr->next;
    }
    lessTail->next = nullptr;
    equalTail->next = nullptr;
    greaterTail->next = nullptr;
    Node* sortedLess = quickSortLinkedList(lessHead.next);
    Node* sortedGreater = quickSortLinkedList(greaterHead.next);
    Node dummy(0);
    Node* tailPointer = &dummy;
    if (sortedLess) {
        tailPointer->next = sortedLess;
        while (tailPointer->next) {
            tailPointer = tailPointer->next;
        }
    }
    tailPointer->next = equalHead.next;
    while (tailPointer->next) {
        tailPointer = tailPointer->next;
    }
    tailPointer->next = sortedGreater;
    return dummy.next;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        long long val;
        cin >> val;
        insertNode(head, tail, val);
    }
    head = quickSortLinkedList(head);
    printList(head);
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}