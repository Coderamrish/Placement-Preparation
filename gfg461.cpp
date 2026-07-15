/*
Given two integers n and sum, determine the number of n-digit positive integers whose digits add up to sum.

An n-digit number cannot have leading zeros; that is, the first digit must be between 1 and 9.
If there exist no n digit number with sum of digits equal to given sum, return -1.
Examples :

Input: n = 2, sum = 2
Output: 2
Explaination: The valid 2-digit numbers whose digits sum to 2 are 11 and 20.
Input: n = 1, sum = 10
Output: -1
Explaination: A single-digit number can only have a digit sum between 0 and 9.
Input: n = 2, sum = 10
Output: 9
Explaination: The 2-digit numbers whose digits add up to 10 are: 19, 28, 37, 46, 55, 64, 73, 82, 91.

Constraints:

1 ≤ n ≤ 9
1 ≤ sum ≤ 81
 Tabulation - O(n * sum) Time and O(n * sum) Space
The idea is to build the answer in a bottom-up manner using dynamic programming. We create a 2D DP table where dp[len][s] stores the number of ways to form a digit sequence of length len whose digits add up to s. 

We start with the base case dp[0][0] = 1, representing one way to achieve a sum of 0 using 0 digits.
Then, for each length and sum, we consider all possible digits from 0 to 9 and use previously computed states to update the current state.
By filling the table systematically, every subproblem is solved exactly once.
Since the first digit of an n-digit number cannot be 0, we choose the first digit from 1 to 9 and use the DP table to count the valid ways to form the remaining digits.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countWays(int n, int sum) {
    if(sum > 9 * n || sum < 1) return -1;
vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
dp[0][0] = 1;
for(int len = 1; len <= n; len++) {
    for(int s = 0; s <= sum; s++) {
        for(int digit = 0; digit <= 9; digit++) {
            if(s >= digit) {
                dp[len][s] += dp[len - 1][s - digit];
            }
        }
    }
}
int ans = 0;
for(int digit = 1; digit <= 9; digit++) {
    if(sum >= digit) {
        ans += dp[n - 1][sum - digit];
    }
}
return (ans == 0) ? -1 : ans;
}
int main() {
    int n, sum;
    cin >> n >> sum;
    cout << countWays(n, sum);
    return 0;
}