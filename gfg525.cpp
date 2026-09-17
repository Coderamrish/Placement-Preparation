/*
Given the root of a Binary Search Tree (BST) containing n (n > 1) nodes, find the minimum absolute difference between the values of any two different nodes in the tree.
Return the minimum absolute difference.
Examples:
Input: root[] = [50, 30, 70, 20, N, 60, 80]
420046990
Output: 10
Explanation: There are no two nodes whose absolute difference is smaller than 10.
Input: root[] = [60, 30, 90, 10]
2056957925
Output: 20
Explanation: There are no two nodes whose absolute difference is smaller than 20.
Constraints:
2 ≤ size of binary tree ≤ 105
0 ≤ node.data ≤ 106
*/
#include <bits/stdc++.h> 
using namespace std; 
class Node { 
public:
    int data; 
    Node* left; 
    Node* right; 
    Node(int data) 
    { 
        this->data = data; 
        left = nullptr; 
        right = nullptr; 
    } 
}; 
void inorder(Node* curr, Node*& prev, int& ans) 
{
    if (curr == nullptr) 
        return; 
    inorder(curr->left, prev, ans); 
    if (prev!= nullptr) 
        ans = min(ans, curr->data - prev->data); 
    prev = curr;  
    inorder(curr->right, prev, ans); 
} 
int absDiff(Node* root) 
{ 
    Node* prev = nullptr;  
    int ans = INT_MAX;         
    inorder(root, prev, ans); 
    return ans; 
} 
int main() 
{ 
    Node* root = new Node(5); 
    root->left = new Node(3); 
    root->right = new Node(7); 
    root->left->left = new Node(2); 
    root->left->right = new Node(4); 
    root->right->left = new Node(6); 
    root->right->right = new Node(8); 
    cout << absDiff(root); 
    return 0; 
}