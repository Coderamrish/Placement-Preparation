/*
Given a binary matrix of size M × N consisting of 0s and 1s,
where 1 represents a valid cell and 0 represents a blocked cell.

You are also given the coordinates of a source cell (xs, ys)
and a destination cell (xd, yd).

Find the length of the longest possible path from the source
to the destination. You can move only in four directions:
up, down, left, and right.

A cell can be visited at most once in a path.

If no valid path exists, print -1.

Input Format:
First line contains two integers M and N.
Next M lines contain N space-separated integers (0 or 1).
Next line contains two integers xs and ys.
Next line contains two integers xd and yd.

Output Format:
Print a single integer representing the length of the
longest path from the source to the destination.
If no such path exists, print -1.

Constraints:
1 <= M, N <= 10
0 <= xs, xd < M
0 <= ys, yd < N
Matrix elements are either 0 or 1.

Sample Input:
3 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 0 1 0 1 1
1 1 1 1 1 1 1 1 1 1
0 0
1 7

Sample Output:
24

Explanation:
The destination cell (1, 7) is blocked (contains 0),
so no valid path exists. Hence, the output is:
-1

-----------------------------------------------------

Sample Input:
3 3
1 1 1
1 1 1
1 1 1
0 0
2 2

Sample Output:
8

Explanation:
One of the longest paths from (0,0) to (2,2) visits every
cell exactly once except the destination, resulting in a
path length of 8.
*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
int dfs(vector<vector<int>>& mat, int i, int j, int x, int y) {
int m = mat.size();
int n = mat[0].size();
if(i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == 0) 
return -1;
if(i == x && j == y)
return 0;
mat[i][j] = 0;
int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};
int maxPath = -1;
for(int k = 0; k < 4; k++) {
    int path = dfs(mat, i+ row[k], j + col[k], x ,y);
    if(path != -1) 
    maxPath = max(maxPath, 1 + path);
}
mat[i][j] = 1;
return maxPath;
}
int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
    int m = mat.size();
    int n = mat[0].size();
    if(mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;
    return dfs(mat, xs, ys,xd,yd);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    if(!(cin >> m >> n)) return 0;
    vector<vector<int>>mat(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    int xs, ys, xd, yd;
    cin >> xs >> ys;
    cin >> xd >> yd;
    cout << longestPath(mat, xs, ys, xd, yd);
    return 0;
}