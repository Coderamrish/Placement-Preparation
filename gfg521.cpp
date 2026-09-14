/*
Given a 2D matrix mat[][] of size n × m, where each cell is either 0 (landmine) or 1 (safe), find the minimum number of steps required to travel from any cell in the leftmost column to any cell in the rightmost column.

You can move only in four directions: up, down, left, and right.
A cell is unsafe if it contains a landmine or is directly adjacent (up, down, left, or right) to a landmine, and such cells must be avoided.
Return -1 if no safe path exists.
Examples:

Input: mat[][] = [[1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 0]]

Output: 6
Explanation: We can see that length of shortest safe route is 6. 

Input: mat[][] = [[1, 1, 1, 1, 1], [1, 1, 0, 1, 1], [1, 1, 1, 1, 1]]

Output: -1
Explanation: There is no possible path from first column to last column.
Constraints:

1 ≤ n, m ≤ 103
0 ≤ mat[i][j] ≤ 1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(vector<vector<int>> &mat, int i, int j) {
        int r = mat.size();
        int c = mat[0].size();
        if (mat[i][j] != 1)
            return false;
        int rowDir[] = {-1, 1, 0, 0};
        int colDir[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int ni = i + rowDir[k];
            int nj = j + colDir[k];
            if (ni >= 0 && ni < r &&
                nj >= 0 && nj < c &&
                mat[ni][nj] == 0) {
                return false;
            }
        }
        return true;
    }
    int shortestPath(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();
        int rowDir[] = {-1, 1, 0, 0};
        int colDir[] = {0, 0, -1, 1};
        queue<array<int, 3>> q;
        for (int i = 0; i < r; i++) {
            if (isSafe(mat, i, 0)) {
                q.push({i, 0, 1});
                mat[i][0] = -1; 
            }
        }
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int i = front[0];
            int j = front[1];
            int dist = front[2];
            if (j == c - 1)
                return dist;
            for (int k = 0; k < 4; k++) {
                int ni = i + rowDir[k];
                int nj = j + colDir[k];
                if (ni >= 0 && ni < r &&
                    nj >= 0 && nj < c &&
                    isSafe(mat, ni, nj)) {
                    q.push({ni, nj, dist + 1});
                    mat[ni][nj] = -1;
                }
            }
        }
        return -1;
    }
};
int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    Solution obj;
    cout << obj.shortestPath(mat) << endl;
    return 0;
}