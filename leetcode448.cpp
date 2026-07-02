/*
You are given an m x n binary matrix grid and an integer health.

You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).

You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.

Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.

Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

 

Example 1:

Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.


Example 2:

Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3

Output: false

Explanation:

A minimum of 4 health points is needed to reach the final cell safely.


Example 3:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.



Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.

 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
2 <= m * n
1 <= health <= m + n
grid[i][j] is either 0 or 1.

*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int health;
    cin >> health;
    constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int initialHealth = health - grid[0][0];
    using T = tuple<int, int, int>;  
    queue<T> q;
    vector<vector<vector<bool>>> seen(m, vector<vector<bool>>(n, vector<bool>(health + 1, false)));
    if (initialHealth > 0) {
        q.push({0, 0, initialHealth});
        seen[0][0][initialHealth] = true;
    }
    bool possible = false;
    while (!q.empty()) {
        auto [i, j, h] = q.front();
        q.pop();
        if (i == m - 1 && j == n - 1 && h > 0) {
            possible = true;
            break;
        }
        for (const auto& dir : kDirs) {
            const int x = i + dir[0];
            const int y = j + dir[1];
            if (x < 0 || x == m || y < 0 || y == n)
                continue;
            const int nextHealth = h - grid[x][y];
            if (nextHealth <= 0 || seen[x][y][nextHealth])
                continue;
            q.push({x, y, nextHealth});
            seen[x][y][nextHealth] = true;
        }
    }
    if (possible) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    return 0;
}