/*
Given a non-negative integer n, you can only change a set bit (1) to an unset bit (0). Find the maximum possible value of n such that its binary representation does not contain three consecutive set bits (111) after performing zero or more allowed operations.
Examples:
Input: n = 2
Output: 2
Explanation: The binary representation of 2 is 10, which does not contain three consecutive set bits. Therefore, no change is required.
Input: n = 7
Output: 6
Explanation: The binary representation of 7 is 111, which contains three consecutive set bits. Changing the rightmost set bit to 0 gives: 111 -> 110. Thus, the maximum possible value is 6.
Constraints:
0 ≤ n ≤ 109
*/
#include <bits/stdc++.h>
using namespace std;
int bits[31];
int dp[31][3];
bool vis[31][3];
int solve(int pos, int ones)
{
    if (pos < 0)
        return 0;
    if (vis[pos][ones])
        return dp[pos][ones];
    vis[pos][ones] = true;
    int res = solve(pos - 1, 0);
    if (bits[pos] == 1 && ones < 2)
    {
        res = max(res, (1 << pos) + solve(pos - 1, ones + 1));
    }
    return dp[pos][ones] = res;
}
int maxValue(int n)
{
    memset(dp, 0, sizeof(dp));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < 31; i++)
        bits[i] = (n >> i) & 1;
    return solve(30, 0);
}
int main()
{
    int n = 7;
    cout << maxValue(n) << "\n";
    return 0;
}