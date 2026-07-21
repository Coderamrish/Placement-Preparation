/*
you are given the values of the nodes of a binary search tree and an integer K
find the Kth smallest element in the bst.
NOTE:
in a BST
All values in the left subtree are smaller than the root
all vlaues in the right subtree are greater than the root.

Example 1:
Nodes = [5, 3, 6, 2, 4, 1]
K = 3
output:
3
*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void inorder(Node* root, int &count, int k, int &answer) {
    if (root == nullptr || count >= k)
        return;
    inorder(root->left, count, k, answer);
    count++;
    if (count == k) {
        answer = root->data;
        return;
    }
    inorder(root->right, count, k, answer);
}
void clearTree(Node* root) {
    if (root == nullptr) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    int k;
    cin >> k;
    int count = 0;
    int answer = -1;
    inorder(root, count, k, answer);
    cout << answer << "\n";
    clearTree(root);
    return 0;
}