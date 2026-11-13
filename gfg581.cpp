/*
Given the roots r1 and r2 of two Binary Search Trees (BST), find all nodes that are present in both trees i.e. the intersection nodes of the two BSTs.
Return the common node values in sorted order.
Examples:
Input: r1 = [5, 1, 10, 0, 4, 7, N, N, N, N, N, N, 9], r2 = [10, 7, 20, 4, 9, N, N]  
Output: [4, 7, 9, 10]
Explanation: The values present in both BSTs are 4, 7, 9, and 10. Hence, the answer is [4, 7, 9, 10].
Input: r1 = [10, 2, 11, 1, 3, N, N], r2 = [2, 1, 3]
Output: [1, 2, 3]
Explanation: The values 1, 2, and 3 are present in both BSTs. Hence, the answer is [1, 2, 3].
Constraints:
1 ≤ size of binary trees ≤ 105
0 ≤ Node.data ≤ 109
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
Node *insert(Node *root, int key) {
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
vector<int> findCommon(Node *r1, Node *r2) {
    stack<Node *> s1, s2;
    vector<int> res;
    while (true) {
        while (r1) {
            s1.push(r1);
            r1 = r1->left;
        }
        while (r2) {
            s2.push(r2);
            r2 = r2->left;
        }
        if (s1.empty() || s2.empty())
            break;
        Node *curr1 = s1.top();
        Node *curr2 = s2.top();
        if (curr1->data == curr2->data) {
            res.push_back(curr1->data);
            s1.pop();
            s2.pop();
            r1 = curr1->right;
            r2 = curr2->right;
        } else if (curr1->data < curr2->data) {
            s1.pop();
            r1 = curr1->right;
            r2 = nullptr;
        } else {
            s2.pop();
            r2 = curr2->right;
            r1 = nullptr;
        }
    }
    return res;
}
int main() {
    Node *r1 = nullptr;
    r1 = insert(r1, 5);
    r1 = insert(r1, 1);
    r1 = insert(r1, 10);
    r1 = insert(r1, 0);
    r1 = insert(r1, 4);
    r1 = insert(r1, 7);
    r1 = insert(r1, 9);
    Node *r2 = nullptr;
    r2 = insert(r2, 10);
    r2 = insert(r2, 7);
    r2 = insert(r2, 20);
    r2 = insert(r2, 4);
    r2 = insert(r2, 9);
    vector<int> res = findCommon(r1, r2);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";
    return 0;
}