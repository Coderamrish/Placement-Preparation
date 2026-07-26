/*
Given two arrays pre[] and preMirror[] of size n containing unique elements, where pre[] represents the preorder traversal of a full binary tree and preMirror[] represents the preorder traversal of its mirror tree, construct the original full binary tree using these traversals.
Note: A general binary tree cannot be uniquely constructed using these two traversals. However, a full binary tree can be constructed uniquely from the given traversals without any ambiguity.
Examples:
Input: pre[] = [0,1,2], preMirror[] = [0,2,1] 
Output: [0, 1, 2]
Explanation: The tree will look like     
Input: pre[] = [1, 2, 4, 5, 3, 6, 7], preMirror[] = [1, 3, 7, 6, 2, 5, 4]
Output: [1, 2, 4, 5, 3, 6, 7]
Explanation: The tree will look like
Constraints:
1 ≤ pre.size() ≤ 105
0 ≤ pre[i] ≤ 109
1 ≤ preMirror.size() ≤ 105
0 ≤ preMirror[i] ≤ 109
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
Node* buildTree(vector<int>& pre, vector<int>& preMirror,
                int& preIndex, int left, int right,
                unordered_map<int,int>& mp, int n) {
    if (preIndex >= n || left > right)
        return nullptr;
    Node* root = new Node(pre[preIndex++]);
    if (left == right || preIndex >= n)
        return root;
    int mirrorIndex = mp[pre[preIndex]];
    root->left = buildTree(pre, preMirror,
                           preIndex,
                           mirrorIndex,
                           right,
                           mp,
                           n);
    root->right = buildTree(pre, preMirror,
                            preIndex,
                            left + 1,
                            mirrorIndex - 1,
                            mp,
                            n);
    return root;
}
Node* constructBinaryTree(vector<int>& pre,
                          vector<int>& preMirror) {
    unordered_map<int,int> mp;
    for (int i = 0; i < preMirror.size(); i++)
        mp[preMirror[i]] = i;
    int preIndex = 0;
    return buildTree(pre,
                     preMirror,
                     preIndex,
                     0,
                     pre.size() - 1,
                     mp,
                     pre.size());
}
void preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> pre(n), preMirror(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> preMirror[i];
    Node* root = constructBinaryTree(pre, preMirror);
    preorder(root);
    return 0;
}