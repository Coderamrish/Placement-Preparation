/*
Given a matrix mat[][] of size n × n, where mat[i][j] represents the maximum number of steps a rat can jump either forward (right) or downward from that cell, find a path for the rat to reach from the top-left cell (0, 0) to the bottom-right cell (n - 1, n - 1). A cell containing 0 is blocked and cannot be used in the path. It is guaranteed that the cell mat[n-1][n-1] is not 0.

Return an n × n matrix where 1 represents the cells included in the path and 0 represents the remaining cells. If no valid path exists, return [[-1]].

Note: If multiple valid paths exist, choose the path with the shortest possible jumps first. For the same jump length, moving forward (right) should be preferred over moving downward.

Example:

Input: mat[][] = [[2, 1, 0, 0], [3, 0, 0, 1], [0, 1, 0, 1], [0, 0, 0, 1]]
Output: [[1, 0, 0, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1]]
Explanation: 

The rat starts from cell (0, 0) which contains value 2, so it can jump at most 2 steps either right or downward. 
Steps:
-> Moves downward to (1, 0) which contains value 3.
-> Jumps 3 steps right to reach (1, 3).
-> Moves downward through (2, 3) and reaches the destination cell (3, 3).
Input: mat[][] = [[2, 1, 0, 0], [2, 0, 0, 1], [0, 1, 0, 1], [0, 0, 0, 1]]
Output: [[-1]]
Explanation: The rat starts at (0, 0) with value 2, but every possible path from there eventually reaches a cell containing 0. Since no sequence of jumps can reach the destination cell (3, 3), no valid path exists and the output is [[-1]].
Constraints:
1 ≤ n ≤ 50
0 ≤ mat[i][j] ≤ 20

Approach - Finding Shortest Valid Path – O(n² × maxJump) Time and O(n²) Space
*/
#include <iostream>
#include <vector>
using namespace std;
bool solve(int i, int j, vector<vector<int>> &mat,
           vector<vector<int>> &ans, vector<vector<int>> &dp)
{
    int n = mat.size();
    if (i >= n || j >= n || mat[i][j] == 0)
        return false;
    if (i == n - 1 && j == n - 1)
    {
        ans[i][j] = 1;
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    ans[i][j] = 1;
    int jump = mat[i][j];
    for (int step = 1; step <= jump; step++)
    {
        if (solve(i, j + step, mat, ans, dp) ||
            solve(i + step, j, mat, ans, dp))
        {
            return dp[i][j] = 1;
        }
    }
    ans[i][j] = 0;
    return dp[i][j] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> mat(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> mat[i][j];
    if (mat[0][0] == 0)
    {
        cout << -1;
        return 0;
    }
    vector<vector<int>> ans(N, vector<int>(N, 0));
    vector<vector<int>> dp(N, vector<int>(N, -1));
    if (!solve(0, 0, mat, ans, dp))
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}