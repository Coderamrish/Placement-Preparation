/*
Given root of a binary tree and the values of its two nodes p and q, count turns required to travel from node p to q.

A turn occurs whenever the direction of movement changes from left to right or right to left while traversing the tree.
If the path between the two nodes does not involve any turns (i.e., the nodes lie on the same straight path), return -1.
Note: All node values are distinct.

Examples :

Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 5, q = 10

Output: 4
Explanation: The path from node 5 to node 10 is: 5 -> 2 -> 1 -> 3 -> 6 → 10. Direction changes occur at nodes 2, 1, 3, and 6. Therefore, the number of turns is 4.
Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 1, q = 4

Output: -1
Explanation: No turn is required since they are in a straight line.
Constraints:
1 ≤ n ≤ 104, n is the number of nodes
1 ≤ node->data ≤ 104
1 ≤ p, q ≤ n
*/
#include <iostream>
#include <string>
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
class Solution {
public:
    Node* findLCA(Node* root, int p, int q) {
        if (root == nullptr)
            return nullptr;
        if (root->data == p || root->data == q)
            return root;
        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);
        if (left && right)
            return root;
        return left ? left : right;
    }
    bool findPath(Node* root, int target, string& path) {
        if (root == nullptr)
            return false;
        if (root->data == target)
            return true;
        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();
        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
    int countTurns(string& path) {
        int turns = 0;
        for (int i = 1; i < path.length(); i++) {
            if (path[i] != path[i - 1])
                turns++;
        }
        return turns;
    }
    int numberOfTurns(Node* root, int p, int q) {
        Node* lca = findLCA(root, p, q);
        if (lca == nullptr)
            return -1;
        string pathFirst = "";
        string pathSecond = "";
        findPath(lca, p, pathFirst);
        findPath(lca, q, pathSecond);
        int turns = 0;
        if (lca->data == p || lca->data == q) {
            string path;
            if (lca->data == p)
                path = pathSecond;
            else
                path = pathFirst;
            turns = countTurns(path);
        }
        else {
            turns = countTurns(pathFirst)
                  + countTurns(pathSecond)
                  + 1;
        }
        if (turns == 0)
            return -1;
        return turns;
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    Solution obj;
    int p = 4;
    int q = 8;
    cout << "Number of turns: "
         << obj.numberOfTurns(root, p, q) << endl;
    return 0;
}