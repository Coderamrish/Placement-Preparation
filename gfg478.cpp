/*
Given two positive integer n and m. Find the number of arrays of size n that can be formed such that:

Each element is in the range [1, m].
All adjacent are such that one of them divide the another i.e element Ai divides Ai + 1 or Ai+1 divides Ai.
Examples:

Input: n = 3, m = 3
Output : 17
Explanation: The possible arrays are [1, 1, 1], [1, 1, 2], [1, 1, 3], [1, 2, 1], [1, 2, 2], [1, 3, 1], [1, 3, 3], [2, 1, 1], [2, 1, 2], [2, 1, 3], [2, 2, 1], [2, 2, 2], [3, 1, 1], [3, 1, 2], [3, 1, 3], [3, 3, 1] and [3, 3, 3].
Input: n = 1, m = 10 
Output: 10
Explanation: The possible arrays are [1], [2], [3], [4], [5], [6], [7], [8], [9] and [10].

Constraints:

1 ≤ n ≤ 11
1 ≤ m ≤ 11

*/
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int countArrays(int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> factors(m + 1);
    vector<vector<int>> multiples(m + 1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j += i)
        {
            factors[j].push_back(i);
            if (j != i)
                multiples[i].push_back(j);
        }
    }
    for (int i = 1; i <= m; i++)
        dp[1][i] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int curr = 1; curr <= m; curr++)
        {
            for (int prev : factors[curr])
            {
                dp[len][curr] = (dp[len][curr] + dp[len - 1][prev]) % MOD;
            }
            for (int prev : multiples[curr])
            {
                dp[len][curr] = (dp[len][curr] + dp[len - 1][prev]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n][i]) % MOD;
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << countArrays(n, m);
    return 0;
}