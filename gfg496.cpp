/*
Given the root of a binary tree, find the maximum difference between an ancestor node A and its descendant node B, i.e., maximize A - B.
Examples :
Input: root[] = [5, 2, 1] 
Output: 4
Explanation: The maximum difference we can get is 4, which is between 5 and 1.
Input: root[] = [1, 2, 3, N, N, N, 7] 
Output: -1
Explanation: The maximum difference we can get is -1, which is between 1 and 2.
Constraints:
2 ≤ no. of nodes in root ≤ 104
0 ≤ root.node->data ≤ 105
2 ≤ Number of edges ≤ 104
*/
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
class Solution {
public:
    int maxDiffUtil(Node* t, int* res) {
        if (t == nullptr)
            return INT_MAX;
        if (t->left == nullptr && t->right == nullptr)
            return t->data;
        int val = min(maxDiffUtil(t->left, res),
                      maxDiffUtil(t->right, res));
        *res = max(*res, t->data - val);
        return min(val, t->data);
    }
    int maxDiff(Node* root) {
        int res = INT_MIN;
        maxDiffUtil(root, &res);
        return res;
    }
};
int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    Solution obj;
    cout << "Maximum Difference = "
         << obj.maxDiff(root) << endl;
    return 0;
}