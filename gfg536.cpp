/*
Given a square chessboard of size n × n, the initial position knightPos and target position targetPos of a Knight are given. Find the minimum number of moves required for the Knight to reach targetPos.
A Knight moves in an L-shape, covering 2 cells in one direction and 1 cell perpendicular to it. From (x, y), it can move to: (x ± 2, y ± 1) and (x ± 1, y ± 2)
This gives at most 8 possible moves:
Note: The positions are given using 1-based indexing.
Examples:
Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
Output: 1
Explanation: Knight takes 1 step to reach from (3, 3) to (1 ,2).
Input: n = 6, knightPos[] = [1, 3], targetPos[] = [5, 1]
Output: 2
Explanation: In above diagram Knight takes 2 step to reach from (1, 3) to (5, 0): (1, 3) -> (3, 2) -> (5, 1)  
Constraints:
n ≤ 1000
2 ≤ knightPos.size(), targetPos.size() ≤ 2
1 ≤ knightPos[i], targetPos[i] ≤ n
*/
#include <bits/stdc++.h>
using namespace std;
int minStepToReachTarget(vector<int>& knightPos,
                         vector<int>& targetPos, int n) {
    int x = knightPos[0] - 1;
    int y = knightPos[1] - 1;
    int tx = targetPos[0] - 1;
    int ty = targetPos[1] - 1;
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    q.push({{x, y}, 0});
    visited[x][y] = true;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        if (x == tx && y == ty)
            return steps;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }
    return -1;
}
int main() {
    int n = 6;
    vector<int> knightPos = {4, 5};
    vector<int> targetPos = {1, 1};
    cout << minStepToReachTarget(knightPos, targetPos, n);
    return 0;
}