/*
Given the root of a Binary Tree, find the length of the longest path consisting of connected nodes such that each next node has a value exactly 1 greater than its parent.

The path must move from parent to child only and follow increasing consecutive values.

If no such path exists, return -1.

Examples:

Input: root[] = [1, 2, 3]

                                
Output: 2
Explanation : Longest sequence is 1, 2. So answer for this test case is 2.
Input : root[] = [10, 20, 30, 40, N, 60, 90]

Output : -1
Explanation: For the above test case no sequence is possible. So output is -1.

Constraints:

1 ≤ no. of nodes in root ≤ 105
1 ≤ root.node->data ≤ 105
*/
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* buildTree() {
    string val;
    cin >> val;
    if(val== "N")
    return NULL;
    Node* root = new Node(stoi(val));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        string leftVal, rightVal;
        if(!(cin >> leftVal))
        break;
        if(leftVal != "N") {
            curr->left = new Node(stoi(leftVal));
            q.push(curr->left);
        }
        if(!(cin >> rightVal))
        break;
        if(rightVal != "N") {
            curr->right = new Node(stoi(rightVal));
            q.push(curr->right);
        }
    }
    return root;
}
void dfs(Node* currentNode, Node* parentNode, int currentLength, int &longestPath) {
    if(currentNode == NULL)
    return;
    if(parentNode != NULL && currentNode->data == parentNode->data + 1)
    currentLength++;
    else
    currentLength = 1;
    longestPath = max(longestPath, currentLength);
    dfs(currentNode->left, currentNode, currentLength, longestPath);
    dfs(currentNode->right, currentNode, currentLength, longestPath);
}
int longestConsecutive(Node* root) {
    if(root == NULL) 
    return -1;
    int longestPath = 0;
dfs(root, NULL, 0, longestPath);
return (longestPath == 1) ? -1 : longestPath;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = buildTree();
    cout << longestConsecutive(root);
    return 0;
}