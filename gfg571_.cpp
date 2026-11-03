/*
Given a weighted tree with n nodes, numbered from 1 to n and n - 1 edges, where each edge is represented as [u, v, w] indicating an edge between nodes u and v with weight w.

You are also given an array queries[], where each queries[i] represents a maximum allowed edge weight.

For each query x, find the number of distinct paths in the tree such that the maximum edge weight along the path is less than or equal to x.

Return an array containing the number of valid paths for each query.

Note:

A path from node u to node v and the path from node v to node u are considered the same path.
A path must contain at least one edge. A path from a node to itself is not considered.
Examples:

Input: n = 3, edges[][] = [[1, 2, 1], [2, 3, 4]], queries[] = [3]
Output: [1]
Explanation:
For x = 3, only the edge [1, 2, 1] has weight less than or equal to 3.
Therefore, the only valid path is: 1 -> 2
The path 1 -> 3 contains an edge of weight 4, so it is not valid.
Hence, the answer is 1.
Input: n = 7, edges[][] = [[1, 2, 3], [2, 3, 1], [2, 4, 9], [3, 6, 7], [3, 5, 8], [5, 7, 4]], queries[] = [1, 3, 5]
Output: [1, 3, 4]
Explanation: For x = 1, only the edge [2, 3, 1] satisfies the condition. 
Therefore, the only valid path is 2 -> 3, giving an answer of 1.
For x = 3, the edges [2, 3, 1] and [1, 2, 3] can be used. 
They form three valid paths: 1 -> 2, 2 -> 3, and 1 -> 3. 
For x = 5, the edges with weights 1, 3, and 4 can be used. 
They form four valid paths: 1 -> 2, 2 -> 3, 1 -> 3, and 5 -> 7.
Constraints:

2 ≤ n ≤ 104
1 ≤ queries.size() ≤ 104
0 ≤ queries[i] ≤ 105
edges.size() = n-1
edges[i].size() = 3
1 ≤ edges[i][0], edges[i][1] ≤ n
edges[i][0] != edges[i][1]
0 ≤ edges[i][2] ≤ 105
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;
int ans;
int root(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    return parent[x] = root(parent[x], parent);
}
void Union(int a, int b, vector<int> &parent, vector<int> &sz)
{
    int ra = root(a, parent);
    int rb = root(b, parent);
    if (ra == rb)
        return;
    if (sz[ra] < sz[rb])
        swap(ra, rb);
    ans += sz[ra] * sz[rb];
    parent[rb] = ra;
    sz[ra] += sz[rb];
}
vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int> &queries)
{
    ans = 0;
    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    vector<array<int, 3>> wt;
    for (auto &e : edges)
    {
        wt.push_back({e[2], e[0], e[1]});
    }
    sort(wt.begin(), wt.end());
    map<int, int> mp;
    int i = 0;
    while (i < (int)wt.size())
    {
        int weight = wt[i][0];
        while (i < (int)wt.size() && wt[i][0] == weight)
        {
            int u = wt[i][1];
            int v = wt[i][2];
            Union(u, v, parent, sz);
            i++;
        }
        mp[weight] = ans;
    }
    vector<int> res;
    res.reserve(queries.size());
    for (int x : queries)
    {
        auto it = mp.upper_bound(x);

        if (it == mp.begin())
        {
            res.push_back(0);
        }
        else
        {
            --it;
            res.push_back(it->second);
        }
    }
    return res;
}
int main()
{
    int n = 7;
    vector<vector<int>> edges = {{1, 2, 3}, {2, 3, 1}, {2, 4, 9}, {3, 6, 7}, {3, 5, 8}, {5, 7, 4}};
    vector<int> queries = {1, 3, 5};
    vector<int> ans = maximumWeight(n, edges, queries);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0)
            cout << ", ";
        cout << ans[i];
    }
    cout << "]\n";
    return 0;
}