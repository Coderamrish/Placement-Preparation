/*
Given the root of a binary tree, where each node contains an integer value, find the maximum possible path sum between any two leaf nodes. If the tree has fewer than two leaf nodes, return -1.

Examples:

Input: root = [3, 4, 5, -10, 4, N, N]
                   
Output: 16
Explanation: 

The leaf nodes are -10, 4 (right child of 4), and 5.
Possible paths between leaf nodes are:
-10 -> 4 -> 3 -> 5 = -10 + 4 + 3 + 5 = 2
-10 -> 4 -> 4 = -10 + 4 + 4 = -2
4 -> 4 -> 3 -> 5 = 4 + 4 + 3 + 5 = 16
Hence, the maximum path sum is obtained from the path 4 -> 4 -> 3 -> 5, giving 16.
Input: root = [-15, 5, 6, -8, 1, 3, 9, 2, -3, N, N, N, N, N, 0, N, N, N, N, 4, -1, N, N, 10]

Output: 27
Explanation: 

The leaf nodes are 2, -3, 1, 4, and 10.
Some possible paths between leaves are:
2 -> -8 -> 5 -> 1 = 2 + (-8) + 5 + 1 = 0
-3 -> -8 -> 5 -> 1 = -3 + (-8) + 5 + 1 = -5
2 -> -8 -> 5 -> -15 -> 6 -> 3 = 2 + (-8) + 5 + (-15) + 6 + 3 = -7
1 -> 5 -> -15 -> 6 -> 9 -> 0 -> 4 = 1 + 5 + (-15) + 6 + 9 + 0 + 4 = 10
3 -> 6 -> 9 -> 0 -> -1 -> 10 = 3 + 6 + 9 + 0 + (-1) + 10 = 27
Hence, the maximum path sum is obtained from the path 3 -> 6 -> 9 -> 0 -> -1 -> 10, giving 27.
Input: root = [3, 4, 1, -10, 4, N, N] 
                         
Output: 12
Explanation:

The leaf nodes are -10, 4 (right child of 4), and 1.
Possible paths between leaf nodes are:
-10 -> 4 -> 4 = -10 + 4 + 4 = -2
-10 -> 4 -> 3 -> 1 = -10 + 4 + 3 + 1 = -2
4 -> 4 -> 3 -> 1 = 4 + 4 + 3 + 1 = 12
Hence, the maximum path sum is obtained from the path 4 -> 4 -> 3 -> 1, giving 12.
Constraints:

0 ≤ size of binary tree ≤ 104
-103 ≤ node.data ≤ 103
*/
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
int maxPathSumUtil(Node *root, int &res) {
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return root->data;
    int leftSum = maxPathSumUtil(root->left, res);
    int rightSum = maxPathSumUtil(root->right, res);
    if (root->left && root->right) {
        res = max(res, leftSum + rightSum + root->data);
        return max(leftSum, rightSum) + root->data;
    }
    if (root->left)
        return leftSum + root->data;
    return rightSum + root->data;
}
int maxPathSum(Node *root) {
    if (root == nullptr)
        return -1;
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res == INT_MIN ? -1 : res;
}
int main() {
    Node *root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(-10);
    root->left->right = new Node(4);
    cout << maxPathSum(root);
    return 0;
}