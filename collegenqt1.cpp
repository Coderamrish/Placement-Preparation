/*
Problem: Treasure Hunt in the Magical Kingdom
A king has created a treasure map represented by an N × M grid. Each cell of the grid contains some amount of gold coins.
A brave soldier starts his journey from the top-left corner of the map (0,0) and wants to reach the treasure location at the bottom-right corner (N-1,M-1).
The soldier can move only in two directions:
Right → Move to the next cell in the same row.
Down → Move to the next cell in the same column.
The soldier collects all the coins present in the cells he visits, including the starting and ending cells.
Your task is to help the soldier find the maximum number of coins he can collect by choosing the best possible path.
Input Format:
The first line contains two integers N and M, representing the number of rows and columns.
The next N lines contain M integers each, representing the number of coins in each cell.
Output Format:
Print a single integer representing the maximum number of coins collected.
Constraints:
1 ≤ N, M ≤ 1000
0 ≤ grid[i][j] ≤ 10000
Sample Input:
3 3
1 2 3
4 5 6
7 8 9
Sample Output:
29
Explanation:
The best path is:
1 → 4 → 7 → 8 → 9
Total coins:
1 + 4 + 7 + 8 + 9 = 29
Therefore, the maximum coins the soldier can collect is 29.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maximumCoins(vector<vector<int>>& grid) {
    int N = grid.size();
    int M = grid[0].size();
    vector<vector<int>> dp(N, vector<int>(M, 0));
    dp[0][0] = grid[0][0];
    for(int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for(int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < M; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[N - 1][M - 1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >>  M;
    vector<vector<int>> grid(N, vector<int>(M));
for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
        cin >> grid[i][j];
    }
}
cout << maximumCoins(grid) << endl;
return 0;
}