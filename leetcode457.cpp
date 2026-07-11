/*
You are given an undirected graph with N vertices numbered from 0 to N-1
and M edges.

A connected component is called complete if every pair of distinct
vertices in the component is directly connected by an edge.

Your task is to count the number of complete connected components
present in the graph.

Input Format:
First line contains two integers N and M.
Next M lines contain two integers u and v representing an
undirected edge between vertices u and v.

Output Format:
Print a single integer representing the number of complete
connected components.

Constraints:
1 <= N <= 50
0 <= M <= N * (N - 1) / 2
0 <= u, v < N
u != v
There are no duplicate edges.

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<climits>
#include<sstream>
using namespace std;
void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& comp) {
    vis[node] = true;
    comp.push_back(node);
    for(int nei : adj[node]) {
        if(!vis[nei])
        dfs(nei, adj, vis, comp);
    }
}
int countComplete(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for(auto &e : edges) {
       adj[e[0]].push_back(e[1]);
       adj[e[1]].push_back(e[0]);
    }
 vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);
                bool complete = true;
                int sz = comp.size();
                for (int node : comp) {
                    if (adj[node].size() != sz - 1) {
                        complete = false;
                        break;
                    }
                }
                if (complete)
                    ans++;
            }
        }
        return ans;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << countComplete(n, edges);
    return 0;
}