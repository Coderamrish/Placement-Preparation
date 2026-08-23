/*
Given a maze mat[][] of size n × m, where each cell is either:

'.' representing an empty cell, or
'#' representing an obstacle.
Find the number of distinct empty cells that Geek can visit starting from the cell (r, c).

Geek can move up, down, left, or right to an adjacent non-obstacle cell inside the maze.
On any path, Geek can make at most u upward moves and d downward moves.
There is no limit on the number of left or right moves.
If the starting cell is an obstacle, return 0.
Note :  There can be multiple paths starting from [r, c].

Examples:

Input: r = 1, c = 0, u = 1, d = 1, mat = [['.', '.', '.'], ['.', '#', '.'], ['#', '.', '.']]
Output: 5
Explanation: Geek starts from (1, 0) and follows the path (1,0)->(0,0)->(0,1)->(0,2)->(1,2). The cells (1,1) and (2,0) are obstacles, so they cannot be visited. Hence, Geek can visit 5 distinct empty cells.
 
Input: r = 2, c = 1, u = 2, d = 2, mat = [['.', '.', '.'], ['.', '#', '.'], ['.', '.', '.']]
Output: 8
Explanation: Geek starts from (2, 1) and follows the path (2,1)->(2,2)->(1,2)->(0,2)->(0,1)->(0,0)->(1,0)->(2,0). The cell (1,1) is an obstacle, so it cannot be visited. Hence, Geek can visit all 8 empty cells.

Input: r = 2, c = 1, u = 1, d = 0, mat = [['.', '.', '.'], ['.', '#', '.'], ['.', '.', '.']]
Output: 5
Explanation: The paths followed are (2, 1)->(2, 0)->(1, 0) and (2, 1)->(2, 2)->(1, 2)
Constraints:

1 ≤ n, m ≤ 106
0 ≤ r, c < 106
0 ≤ u, d ≤ 106
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        if (mat[r][c] == '#') {
            return 0;
        }
        vector<vector<int>> upUsed(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        upUsed[r][c] = 0;
        q.push({r, c});
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
            int currUp = upUsed[x][y];
            int currDown = currUp + (x - r);
            if (x - 1 >= 0 &&
                mat[x - 1][y] == '.' &&
                currUp + 1 <= u &&
                currUp + 1 < upUsed[x - 1][y]) {   
                upUsed[x - 1][y] = currUp + 1;
                q.push({x - 1, y});
            }
            if (x + 1 < n &&
                mat[x + 1][y] == '.' &&
                currDown + 1 <= d &&
                currUp < upUsed[x + 1][y]) {
                upUsed[x + 1][y] = currUp;
                q.push({x + 1, y});
            }
            if (y - 1 >= 0 &&
                mat[x][y - 1] == '.' &&
                currUp < upUsed[x][y - 1]) {
                upUsed[x][y - 1] = currUp;
                q.push({x, y - 1});
            }
            if (y + 1 < m &&
                mat[x][y + 1] == '.' &&
                currUp < upUsed[x][y + 1]) {
                upUsed[x][y + 1] = currUp;
                q.push({x, y + 1});
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (upUsed[i][j] != INT_MAX) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution obj;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    int r, c, u, d;
    cin >> r >> c >> u >> d;
    cout << obj.numberOfCells(r, c, u, d, mat) << endl;
    return 0;
}