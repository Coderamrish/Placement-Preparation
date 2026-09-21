/*
Given the roots of two binary trees root1 and root2, check whether the nodes at every corresponding level of the two trees are anagrams of each other.

Two levels are considered anagrams if they contain the same node values with the same frequencies, regardless of their order.

Examples:

Input: root1 = [1, 3, 2, N, N, 5, 4], root2 = [1, 2, 3, 4, 5, N, N]

Output: true
Explanation: 
Level 0: [1] and [1]
Level 1: [3, 2] and [2, 3]
Level 2: [5, 4] and [4, 5]
The node values at every corresponding level are anagrams of each other. Hence, the answer is true.
Input: root1 = [1, 2, 3, 5, 4], root2 = [1, 2, 4, 5, 3]

Output: false
Explanation: 
Level 0: [1] and [1]
Level 1: [2, 3] and [2, 4]
Since the node values at level 1 are not anagrams, the answer is false.
Constraints:

1 ≤ size of binary tree ≤ 105
1 ≤ node.data ≤ 106
The character N represents a null child.
*/
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
class Node
{
  public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
bool areAnagrams(Node *root1, Node *root2)
{
    if (root1 == nullptr || root2 == nullptr)
        return root1 == root2;
    queue<Node *> q1;
    queue<Node *> q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty())
    {
        int n1 = q1.size();
        int n2 = q2.size();
        if (n1 != n2)
            return false;
        unordered_map<int, int> freq;
        for (int i = 0; i < n1; i++)
        {
            Node *node1 = q1.front();
            Node *node2 = q2.front();
            q1.pop();
            q2.pop();
            freq[node1->data]++;
            freq[node2->data]--;
            if (node1->left != nullptr)
                q1.push(node1->left);
            if (node1->right != nullptr)
                q1.push(node1->right);
            if (node2->left != nullptr)
                q2.push(node2->left);
            if (node2->right != nullptr)
                q2.push(node2->right);
        }
        for (const auto &entry : freq)
        {
            if (entry.second != 0)
                return false;
        }
    }
    return q1.empty() && q2.empty();
}
int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->right->left = new Node(5);
    root1->right->right = new Node(4);
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    cout << boolalpha << areAnagrams(root1, root2) << "\n";
    return 0;
}