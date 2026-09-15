/*
Given a binary tree and an integer k, where you start from the root at level 1. The cost of visiting a leaf node is equal to the level of that leaf node. You can visit any number of leaf nodes, but the total cost of visiting them must not exceed k.

Return the maximum number of leaf nodes that can be visited within the given budget.

Examples:

Input: root[] = [10, 8, 2, 3, N, 3, 6, N, N, N, 4], k = 8

Output: 2
Explanation:
Cost For visiting Leaf Node 3: 3
Cost For visiting Leaf Node 4: 4
Cost For visiting Leaf Node 6: 3
To maximize the number of visited leaves, choose the two cheapest leaves: Cost = 3 + 3 = 6 ≤ 8. 
Thus, the maximum number of leaf nodes that can be visited is 2.
Input: root[] = [1, 2, 3, 4, 5, 6, 7], k = 5

Output: 1
Explanation: The leaf nodes are 4, 5, 6 and 7, and all are at level 3. Therefore, visiting each leaf costs 3. With a budget of 5, we can visit only one leaf because: 3 ≤ 5, but 3 + 3 > 5. Thus, the maximum number of leaf nodes that can be visited is 1.
Input: root[] = [1], k = 1         
Output: 1
Explanation: The root node is also a leaf node and is at level 1. Therefore, its visiting cost is 1. Thus, the maximum number of leaf nodes that can be visited is 1.
Constraints:

1 ≤ size of binary tree ≤ 105
1 ≤ k ≤ 104

*/
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
public:
    int getCount(Node *root, int k) {
        if (!root)
            return 0;
        queue<Node*> q;
        q.push(root);
        int level = 1;
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            int leafCount = 0;
            for (int i = 0; i < size; i++) {
                Node *curr = q.front();
                q.pop();
                if (!curr->left && !curr->right)
                    leafCount++;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            int canVisit = k / level;
            int take = min(leafCount, canVisit);
            cnt += take;
            k -= take * level;
            if (k < level)
                break;
            level++;
        }
        return cnt;
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<Node*> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        nodes[i] = new Node(value);
    }
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        if (left != -1)
            nodes[i]->left = nodes[left];
        if (right != -1)
            nodes[i]->right = nodes[right];
    }
    Solution obj;
    cout << obj.getCount(nodes[1], k) << endl;
    return 0;
}