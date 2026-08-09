/*
Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.
Alice and Bob take turns, with Alice starting first.
On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.
The game continues until all the stones have been taken.
Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
Example 1:
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:
If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.
Example 2:
Input: piles = [1,2,3,4,5,100]
Output: 104
Constraints
1 <= piles.length <= 100
1 <= piles[i] <= 104
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<int> suffixSum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suffixSum[i] = piles[i] + suffixSum[i + 1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int M = 1; M <= n; M++) {
            for (int X = 1; X <= 2 * M; X++) {
                if (i + X > n) {
                    break;
                }
                int nextM = max(M, X);
                int current = suffixSum[i] - dp[i + X][nextM];

                dp[i][M] = max(dp[i][M], current);
            }
        }
    }
    return dp[0][1];
}
int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    int result = stoneGameII(piles);
    cout << result << endl;
    return 0;
}