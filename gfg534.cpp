/*
Given an undirected acyclic graph (tree) with n nodes numbered from 1 to n. Each node is colored either Red (R) or Blue (B).

The colors of the nodes are given by a string s of length n, where:

s[i] = 'R' means node i + 1 is Red.
s[i] = 'B' means node i + 1 is Blue.
You are also given a list of n - 1 edges edges[][], where each edges[i] = [u, v] represents an undirected edge between nodes u and v.

You can start from any node and traverse along the edges to form a path.

A path is called valid if, once you visit a Blue node, you cannot visit any Red node after it on the same path.

In other words, a valid path must have the following form:

Only Red nodes, or
Only Blue nodes, or
Some Red nodes followed by some Blue nodes.
A path containing a pattern like Blue -> Red is invalid.
Find the maximum number of nodes in a valid path.

Examples:

Input: s = "RBB", edges = [[1, 2], [1, 3]] 
  
Output: 2
Explanation: The longest path is either 1 -> 2 or 1 -> 3. In both cases, the length of the path is 2.
Input: s = "BB", edges = [[1, 2]]
  
Output: 2
Explanation: The longest path is 1 -> 2. The length of the path is 2.
Constraints:

s.size() ≤ 105
1 ≤ edges[i][j] ≤ s.size()
s consists only of the characters R and B
edges.size() = s.size()-1
*/
#include <iostream>
#include <vector>
using namespace std;
void root(vector<vector<int>> &adj, string &s, 
        vector<vector<int>> &sa, int node = 0, int par = -1)
{
    int ra = 0, ba = 0;
    for (auto &it : adj[node])
    {
        if (it == par)
            continue;
        root(adj, s, sa, it, node);
        ra = max(ra, sa[it][0]);
        ra = max(ra, sa[it][1]);
        ba = max(ba, sa[it][1]);
    }
    if (s[node] == 'R')
    {
        sa[node][0] = ra + 1;
        sa[node][1] = 0;
    }
    else
    {
        sa[node][0] = ba + 1;
        sa[node][1] = ba + 1;
    }
}
void reroot(vector<vector<int>> &adj, string &s, vector<vector<int>> &ans, 
            vector<vector<int>> &sa, int node = 0, int par = -1, 
            int red_par = 0, int blue_par = 0)
{
    if (s[node] == 'R')
    {
        ans[node][0] = max(sa[node][0], 1 + red_par);
        ans[node][1] = 0;
    }
    else
    {
        ans[node][0] = max(sa[node][0], 1 + blue_par);
        ans[node][1] = max(sa[node][1], 1 + blue_par);
    }
    int fr = red_par, sr = red_par;
    int fb = blue_par, sb = blue_par;
    for (auto &it : adj[node])
    {
        if (it == par)
            continue;
        if (sa[it][0] > fr)
        {
            sr = fr;
            fr = sa[it][0];
        }
        else if (sa[it][0] > sr)
        {
            sr = sa[it][0];
        }
        if (sa[it][1] > fb)
        {
            sb = fb;
            fb = sa[it][1];
        }
        else if (sa[it][1] > sb)
        {
            sb = sa[it][1];
        }
    }
    for (auto &it : adj[node])
    {
        if (it == par)
            continue;
        int new_red = 0, new_blue = 0;
        if (s[node] == 'R')
        {
            new_red = 1;
            if (sa[it][0] == fr)
                new_red += sr;
            else
                new_red += fr;
            new_blue = 0;
        }
        else
        {
            new_red = 1;
            if (sa[it][1] == fb)
                new_red += sb;
            else
                new_red += fb;
            new_blue = new_red;
        }
        reroot(adj, s, ans, sa, it, node, new_red, new_blue);
    }
}
int longestPath(string &s, vector<vector<int>> &edges)
{
    int n = s.size();
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
        adj[e[0] - 1].push_back(e[1] - 1);
        adj[e[1] - 1].push_back(e[0] - 1);
    }
    vector<vector<int>> subTreeAns(n, vector<int>(2));
    root(adj, s, subTreeAns);
    vector<vector<int>> ans(n, vector<int>(2));
    reroot(adj, s, ans, subTreeAns);
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max({res, ans[i][0], ans[i][1]});
    return res;
}
int main()
{
    string s = "RBB";
    vector<vector<int>> edges = {{1, 2}, {1, 3}};
    cout << longestPath(s, edges) << endl;
    return 0;
}