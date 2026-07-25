/*
Given two linked list, merge them by selecting elements alternatively from each list.
Rules:
Merge nodes alternatively
if one list finishes earlier, append the remaining nodes of the other list
After merging , only the elements at even position(2nd, 4th, 6th,.. )should be shorted in ascending order using bubble sort.
Elements at odd position remain unchanged
Example:
Input:
List1
1 -> 5-> 7
List2
8 -> 2 -> 6 -> 4
Merged list
1 8 5 2 7 6 4
Even position
8 2 6
After bubble sort
2 6 8
Final output:
1 2 5 6 7 8 4
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<climits>
#include<sstream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* createList(int n) {
    if(n == 0) return NULL;
    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* tail = head;
    for(int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }
    return head;
}
Node* mergeAlternate(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;
    while(l1 && l2) {
        tail->next = l1;
        l1 = l1->next;
        tail = tail->next;
        tail->next = l2;
        l2 = l2->next;
        tail = tail->next;
    }
    while(l1) {
        tail->next = l1;
        l1 = l1->next;
        tail = tail->next;
    }
    while(l2) {
        tail->next = l2;
        l2 = l2->next;
        tail = tail->next;
    }
    tail->next = NULL;
    return dummy.next;
}
void sortEvenPosititons(Node* head) {
    vector<Node*> evenNodes;
    Node* temp = head;
    int pos = 1;
    while(temp) {
        if(pos % 2 == 0)
        evenNodes.push_back(temp);
        temp = temp->next;
        pos++;
    }
    int m = evenNodes.size();
    for(int i =0; i < m- 1; i++) {
        for(int j = 0; j < m - i - 1; j++) {
            if(evenNodes[j]-> data > evenNodes[j + 1]->data)
            swap(evenNodes[j]->data, evenNodes[j+1]->data);
        }
    }
}
void printList(Node* head) {
    while(head) {
        cout << head->data;
        if(head->next)
        cout << " ";
        head = head->next;
    }
}
int main() {
    int n1;
    cin >> n1;
    Node* list1 = createList(n1);
    int n2;
    cin >> n2;
    Node* list2 = createList(n2);
    Node* merged = mergeAlternate(list1, list2);
    sortEvenPosititons(merged);
    printList(merged);
    return 0;
}