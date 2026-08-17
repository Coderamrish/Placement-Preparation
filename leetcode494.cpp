/*
There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's score is initially zero.

Return the maximum score that Alice can obtain.

 

Example 1:

Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
Example 2:

Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28
Example 3:

Input: stoneValue = [4]
Output: 0
 

Constraints:

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 106
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> stoneValue(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stoneValue[i];
    }
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++)
    {
        for (int l = 0; l + len - 1 < n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
            {
                int leftSum = prefix[k + 1] - prefix[l];
                int rightSum = prefix[r + 1] - prefix[k + 1];
                if (leftSum < rightSum)
                {
                    dp[l][r] = max(
                        dp[l][r],
                        leftSum + dp[l][k]
                    );
                }
                else if (leftSum > rightSum)
                {
                    dp[l][r] = max(
                        dp[l][r],
                        rightSum + dp[k + 1][r]
                    );
                }
                else
                {
                    dp[l][r] = max(
                        dp[l][r],
                        leftSum + max(dp[l][k], dp[k + 1][r])
                    );
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}