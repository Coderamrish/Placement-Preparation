/*
Given root of a Binary Search Tree (BST) and an integer k, find the minimum absolute difference between k and the value of any node in the BST.
Examples:
Input: root = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4], k = 13
Output: 2
Explanation: The node with value 11 is closest to k = 13. So, the minimum absolute difference is |11 - 13| = 2.
Input: root = [8, 1, 9, N, 4, N, 10, 3], k = 9
Output: 0
Explanation: The node with value 9 is closest to k = 9. So, the minimum absolute difference is |9 - 9| = 0.
Constraints:
1 ≤ size of binary tree, k ≤ 105
0 ≤ Node.data ≤ 105
*/

#include <iostream>
#include<climits>
using namespace std;
class Node
{
  public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
int minDiff(Node *root, int k)
{
    int res = INT_MAX;
    Node *current = root;
    while (current != nullptr) {
        res = min(res, abs(current->data - k));
        if (current->data > k) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return res;
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(11);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(6);
    root->left->right->left->right = new Node(4);
    int k = 13;
    cout << minDiff(root, k);
    return 0;
}