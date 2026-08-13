/*
Given a weighted Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1, represented by edges[][], where edges[i] = [u, v, w] denotes a directed edge from u to v with weight w, and a source vertex src.

Return the distance array, where the value at index i represents the longest distance from s to vertex i.
If a vertex is unreachable from s, store INT_MIN for that vertex. The driver code will automatically display INT_MIN as INF.
Examples :

Input: V = 4, src = 0, edges[][] = [[0, 1, 1], [0, 2, 1], [1, 2, 5], [3, 1, 2], [3, 2, -1]]
Output: [0, 1, 6, INF]
Explanation: The longest distance of vertex 1 from 0 is 1, vertex 2 is 6 and vertex 3 is unreachable so INF.

Input: V = 5, src = 1, edges[][] = [[0, 1, 1], [0, 2, 2], [1, 4, 4], [3, 2, -1], [4, 2, 3], [4, 3, 6]]
Output: [INF, 0, 9, 10, 4]
Explanation: The vertex 0 is not reachable from vertex 1 so its distance is INF, for 2 it is 9, for 3 it is 10, and for 4 it is 4.

Constraints:
1 ≤ V ≤ 104
0 ≤ src ≤ V-1
1 ≤ edges.size() ≤ V * (V - 1) / 2
0 ≤ edges[i][0], edges[i][1] < V
-100 ≤ edges[i][2] ≤ 100
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V);
    vector<int> indegree(V, 0);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        indegree[v]++;
    }
    int src;
    cin >> src;
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);
        for (auto &edge : graph[node]) {
            int v = edge.first;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    vector<int> dist(V, INT_MIN);
    dist[src] = 0;
    for (int node : topoOrder) {
        if (dist[node] == INT_MIN) {
            continue;
        }
        for (auto &edge : graph[node]) {
            int v = edge.first;
            int wt = edge.second;
            dist[v] = max(dist[v], dist[node] + wt);
        }
    }
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MIN) {
            cout << "INF";
        } else {
            cout << dist[i];
        }
        if (i != V - 1) {
            cout << " ";
        }
    }
    return 0;
}