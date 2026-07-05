/*
You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

In case there is no path, return [0, 0].

 

Example 1:

Input: board = ["E23","2X2","12S"]
Output: [7,1]
Example 2:

Input: board = ["E12","1X1","21S"]
Output: [4,2]
Example 3:

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 

Constraints:

2 <= board.length == board[i].length <= 100

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        constexpr int kMod = 1'000'000'007;
        constexpr int kDirs[3][2] = {{0, 1}, {1, 0}, {1, 1}};
        const int n = board.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> count(n + 1, vector<int>(n + 1, 0));
        dp[n - 1][n - 1] = 0;
        count[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'S' || board[i][j] == 'X')
                    continue;
                int max_prev_score = -1;
                int paths_sum = 0;
                for (const auto& dir : kDirs) {
                    const int x = i + dir[0];
                    const int y = j + dir[1];
                    if (dp[x][y] > max_prev_score) {
                        max_prev_score = dp[x][y];
                        paths_sum = count[x][y];
                    } else if (dp[x][y] == max_prev_score && max_prev_score != -1) {
                        paths_sum = (paths_sum + count[x][y]) % kMod;
                    }
                }
                if (max_prev_score != -1) {
                    dp[i][j] = max_prev_score;
                    if (board[i][j] != 'E') {
                        dp[i][j] += (board[i][j] - '0');
                    }
                    count[i][j] = paths_sum;
                }
            }
        }
        if (dp[0][0] == -1) {
            return {0, 0};
        }
        return {dp[0][0], count[0][0]};
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        vector<string> board(n);
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
        }  
        Solution solver;
        vector<int> result = solver.pathsWithMaxScore(board);
        cout << "[" << result[0] << "," << result[1] << "]\n";
    }
    return 0;
}