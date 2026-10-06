/*
Given a matrix with n rows and m columns. Your task is to find the length of the longest path in with the following constraints
The values in path strictly increasing.  For example if a path of length k has values a1, a2, a3, .... ak  , then for every i from [2, k] this condition must hold ai > ai-1. 
No cell should be revisited in the path.
From each cell,  you can move in any of of the four directions: left, right, up, or down.
You are not allowed to move diagonally or move outside the boundary.
Examples:
Input: n = 3, m = 3, matrix[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 5
Explanation: One such path is 1 -> 2 -> 3 -> 6 -> 9, where each number is strictly greater than the previous.
Input: n = 3, m = 3, matrix[][] = [[3, 4, 5], [6, 2, 6], [2, 2, 1]]
Output: 4
Explanation: One of the longest increasing paths is 3 -> 4 -> 5 -> 6.
Constraints:
1 ≤ n, m ≤ 1000
0 ≤ matrix[i][j] ≤ 230
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        vector<pair<int, int>> dir = {
            {0, 1},   
            {1, 0},   
            {0, -1},  
            {-1, 0}   
        };
        vector<vector<int>> degree(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto [dx, dy] : dir) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x >= 0 && x < n &&
                        y >= 0 && y < m &&
                        matrix[x][y] < matrix[i][j]) {
                        degree[i][j]++;
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (degree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            ans++;
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();
                for (auto [dx, dy] : dir) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x >= 0 && x < n &&
                        y >= 0 && y < m &&
                        matrix[x][y] > matrix[i][j]) {
                        degree[x][y]--;
                        if (degree[x][y] == 0) {
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    cout << obj.longIncPath(matrix, n, m) << endl;
    return 0;
}