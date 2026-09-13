/*
Geek Town has n houses numbered from 1 to n, choose a house to host a party such that its distance from its farthest house is as small as possible. Return this minimum possible distance.
The houses are connected by n − 1 bidirectional roads, forming a tree. 
The connections are given as an adjacency list adj, where adj[i] contains all houses directly connected to house i + 1. 
Examples:

Input: adj[][] = [[2], [1, 4, 3], [2], [2]] 

Output: 1
Explanation: Party should take place at house number 2. Maximum distance from house number 2 is 1.
Input: adj[][] = [[2], [1, 3], [4, 2], [3]]

Output: 2
Explanation: Party should take place at house number 2 or 3. The minimum distance is 2.
Constraints:

1 ≤ n ≤ 105
1 ≤ adj[i][j]
adj.size() = n
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int, int> bfs(vector<vector<int>>& adj, int start) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        int farthestNode = start;
        int farthestDist = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : adj[node]) {
                next--;
                if (dist[next] == -1) {
                    dist[next] = dist[node] + 1;
                    q.push(next);
                    if (dist[next] > farthestDist) {
                        farthestDist = dist[next];
                        farthestNode = next;
                    }
                }
            }
        }
        return {farthestNode, farthestDist};
    }
    int partyHouse(vector<vector<int>>& adj) {
        int n = adj.size();
        pair<int, int> first = bfs(adj, 0);
        int diameterEnd = first.first;
        pair<int, int> second = bfs(adj, diameterEnd);
        int diameter = second.second;
        return (diameter + 1) / 2;
    }
};
int main() {
    Solution obj;
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v);
        adj[v - 1].push_back(u);
    }
    cout << obj.partyHouse(adj) << endl;
    return 0;
}