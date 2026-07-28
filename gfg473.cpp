/*
Given a weighted undirected graph with V vertices numbered from 0 to V - 1, represented by an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi. (wi can only be 1 or 2), and two vertices src and dest, find the shortest distance from src to dest.

The shortest distance is defined as the minimum total weight required to reach dest starting from src.

Return the shortest distance from src to dest. If dest is not reachable from src, return -1.

Examples:

Input: V = 4, edges[][] = [[0, 1, 1], [0, 2, 2], [2, 3, 1], [1, 2, 1], [1, 3, 2]], src = 0, dest = 3

Output: 3
Explanation: One of the shortest paths from vertex 0 to vertex 3 is 0 -> 1 -> 3 with a total weight of 1 + 2 = 3.
Another shortest path is 0 -> 2 -> 3 with a total weight of 2 + 1 = 3.
Hence, the shortest distance from 0 to 3 is 3. 
Input: V = 5, edges[][] = [[0, 1, 1], [0, 2, 2], [1, 2, 1], [3, 4, 2]], src = 1, dest = 3

 Output: -1
Explanation: There is no path from vertex 1 to vertex 3, so the answer is -1. 
Input: V = 5, edges[][] = [[1, 0, 1], [0, 3, 2], [1, 3, 1], [1, 2, 2], [2, 3, 2], [3, 4, 1], [2, 4, 1]], src = 1, dest = 4

Output: 2
Explanation: The shortest path from vertex 1 to vertex 4 is 1 -> 3 -> 4 with a total weight of 1 + 1 = 2.
Hence, the shortest distance from 1 to 4 is 2.
Constraints:
2 ≤ V ≤ 105
1 ≤ edges.size() ≤ min(2*105,  V*(V-1)/2)
0 ≤ edges[i][0], edges[i][1] ≤ V-1
edges[i][0] != edges[i][1]
1 ≤ edges[i][1] ≤ 2
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int shortestDistance(int V, vector<vector<pair<int, int>>> &adj, int src, int dest) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (d > dist[node])
            continue;
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[adjNode]) {
                dist[adjNode] = dist[node] + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    if (dist[dest] == INT_MAX)
        return -1;
    return dist[dest];
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src, dest;
    cin >> src >> dest;
    cout << shortestDistance(V, adj, src, dest);
    return 0;
}