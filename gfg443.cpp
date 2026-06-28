/*
Given two integers n and k, count the number of binary strings of length n where adjacent 1 appear k times.

Since the answer can be huge, return it modulo 109+7.

Examples:

Input: n = 3, k = 2
Output: 1
Explanation: Possible string is "111" where 2 adjacent 1 appear.
Input: n = 5, k = 2
Output: 6
Explanation: Possible strings are "00111", "10111", "01110", "11100", "11101" and "11011".
Constraints:
1 ≤ n, k ≤ 103
Appraoch - using the dp TC:O(n*k) SC:O(n*k)
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int countString(int n, int k) {
if(k >= n) return 0;
    int mod = 1e9 + 7;
vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
dp[1][0][0] = 1;
dp[1][0][1] = 1;
for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
        dp[i][j][0] = (dp[i - 1][j][0]+dp[i - 1][j][1]) % mod;
        dp[i][j][1] = dp[i-1][j][0];
        if(j > 0) {
            dp[i][j][1] = (dp[i][j][1]+dp[i - 1][j - 1][1]) % mod;
        }
    }
}
return (dp[n][k][0] + dp[n][k][1]) % mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    if(cin >> n >> k) {
        cout << countString(n,k);
        return 0;
    }

}