/*
You are maintaining a project that has n methods numbered from 0 to n - 1.

You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.

There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.

A group of methods can only be removed if no method outside the group invokes any methods within it.

Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.

 

Example 1:

Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]

Output: [0,1,2,3]

Explanation:



Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.

Example 2:

Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]

Output: [3,4]

Explanation:



Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

Example 3:

Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]

Output: []

Explanation:



All methods are suspicious. We can remove them.

 

Constraints:

1 <= n <= 105
0 <= k <= n - 1
0 <= invocations.length <= 2 * 105
invocations[i] == [ai, bi]
0 <= ai, bi <= n - 1
ai != bi
invocations[i] != invocations[j]
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> suspicious(n, 0);
    queue<int> q;
    q.push(k);
    suspicious[k] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int next : adj[node]) {
            if (!suspicious[next]) {
                suspicious[next] = 1;
                q.push(next);
            }
        }
    }
    bool possible = true;
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (!suspicious[u] && suspicious[v]) {
                possible = false;
                break;
            }
        }
        if (!possible)
            break;
    }
    if (!possible) {
        for (int i = 0; i < n; i++)
            cout << i << " ";
    } else {
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                cout << i << " ";
        }
    }
    return 0;
}