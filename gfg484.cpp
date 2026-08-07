/*
Given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation.
Find the minimum number of operations that will be required to connect the graph. If it is not possible to connect the graph, return -1.
Examples: 
Input: n = 4, edges[][] = [[0, 1], [0, 2], [1, 2]]
Output: 1
Explanation: Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
Input: n = 6, edges[][] = [[0,1], [0,2], [0,3], [1,2], [1,3]]
Output: 2
Explanation: Remove edge between (1,2) and(0,3) and add edge between (1,4) and (3,5)
Constraints:
1 ≤ n ≤ 105
1 ≤ m ≤ 105
2 ≤ m (cols) ≤ 2
edges[i][j] < n
edges.rows ≤ m
There are no multi-edges in the graph.
*/
#include <iostream>
#include <vector>
using namespace std;
void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    for (int nei : adj[node]) {
        if (!vis[nei]) {
            dfs(nei, adj, vis);
        }
    }
}
int minEdgesReq(int n, vector<vector<int>>& edges) {
    int m = edges.size();
    if (m < n - 1) {
        return -1;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, false);
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            components++;
            dfs(i, adj, vis);
        }
    }
    return components - 1;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << minEdgesReq(n, edges);
    return 0;
}