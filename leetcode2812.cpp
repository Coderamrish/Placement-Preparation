/*
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

 

Example 1:


Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
Example 2:


Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
Example 3:


Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
 

Constraints:

1 <= grid.length == n <= 400
grid[i].length == n
grid[i][j] is either 0 or 1.
There is at least one thief in the grid.
Approach - Precompute minDist using multi-source BFS.
Initialize safeFactor[0] = min(minDist[0][0], minDist[N-1][N-1]) and track the running result res.
Use a deque starting with cell 0.
For each cell popped:
Update res = min(res, safeFactor[node]).
If destination reached, break.
For each unvisited neighbor:
Compute its safeness as min(safeFactor[current], minDist[neighbor]).
If it maintains the current result, add to front (zero cost); otherwise add to back.
Return res.
TC:Time complexity: 
O
(
n
2
)
O(n 
2
 )
Space complexity: 
O
(
n
2
)
O(n 
2
 )
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    if (!(cin >> N)) return 0;
    vector<vector<int>> grid(N, vector<int>(N));
    deque<int> q;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 1) {
                q.push_back(r * N + c);
                grid[r][c] = 0; 
            } else {
                grid[r][c] = -1;
            }
        }
    }
    constexpr int directions[5] = {0, 1, 0, -1, 0};
    while (!q.empty()) {
        int node = q.front(); 
        q.pop_front();
        int r = node / N, c = node % N;
        for (int i = 0; i < 4; i++) {
            int r2 = r + directions[i];
            int c2 = c + directions[i + 1];
            if (r2 >= 0 && c2 >= 0 && r2 < N && c2 < N && grid[r2][c2] == -1) {
                grid[r2][c2] = grid[r][c] + 1;
                q.push_back(r2 * N + c2);
            }
        }
    }
    vector<int> safeFactor(N * N, -1);
    int res = safeFactor[0] = min(grid[N - 1][N - 1], grid[0][0]);
    q.push_back(0);
    while (!q.empty()) {
        int node = q.front(); 
        q.pop_front();
        int r = node / N, c = node % N;
        res = min(res, safeFactor[node]);
        if (r == N - 1 && c == N - 1) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int r2 = r + directions[i];
            int c2 = c + directions[i + 1];
            int node2 = r2 * N + c2;
            if (r2 >= 0 && c2 >= 0 && r2 < N && c2 < N && safeFactor[node2] == -1) {
                safeFactor[node2] = min(safeFactor[node], grid[r2][c2]);
                if (safeFactor[node2] < res) {
                    q.push_back(node2);
                } else {
                    q.push_front(node2);
                }
            }
        }
    }
    cout << res << "\n";
    return 0;
}