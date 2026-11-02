/*
Given an array edge[] of size n, there are n cells numbered from 0 to n - 1. Each cell has at most one outgoing edge.

For every cell i:

edge[i] is the cell reached from i in one step.
edge[i] = -1 means that cell i has no outgoing edge.
A cycle is a sequence of cells where, by following the outgoing edges, we eventually return to the starting cell. The sum of a cycle is the sum of the indices of all cells in that cycle.

Return the maximum cycle sum. If there is no cycle, return -1.

Examples:

Input: edge[] = [1, 2, 0, -1]
Output: 3
Explanation: There is only one cycle in the graph i.e. 0 -> 1 -> 2 -> 0. Sum of the cell index in that cycle = 0 + 1 + 2 = 3.

Input: edge[] = [2, 0, -1, 2]
Output: -1
Explanation: There is no cycle in the graph. The edges are 1 -> 0 -> 2 <- 3. Hence, 2 has no outgoing edge, so no cycle exists.

Constraints:

2 ≤ edge.size() ≤ 105
-1 ≤ edge[i] < edge.size()
edge[i] != i
*/
#include <bits/stdc++.h>
using namespace std;
int largestSumCycle(vector<int> &edge)
{
    int n = edge.size();
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (edge[i] != -1)
        {
            indegree[edge[i]]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        int next = edge[node];
        if (next != -1)
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    long long ans = -1;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] > 0 && visited[i] == 0)
        {
            long long sum = 0;
            int node = i;
            while (visited[node] == 0)
            {
                visited[node] = 1;
                sum += node;
                node = edge[node];
            }
            ans = max(ans, sum);
        }
    }
    return (int)ans;
}
int main()
{
    vector<int> edge = {1, 2, 0, -1};
    cout << largestSumCycle(edge) << endl;
    return 0;
}