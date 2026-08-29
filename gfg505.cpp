/*
Given a numeric string s containing only digits and an integer n, count the number of non-empty subsequences of s whose numeric value is divisible by n. Return the answer modulo 1e9 + 7.

Examples:

Input: s = "1234", n = 4
Output: 4
Explanation: The subsequences 4, 12, 24 and 124 are divisible by 4.
Input: s = "330", n = 6
Output: 4
Explanation: The subsequences 30, 30, 330 and 0 are divisible by 6.
Constraints:
1 ≤ |s| * n ≤ 106
*/
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    int countSubsequences(std::string s, int n) {
        const int MOD = 1e9 + 7;
        std::vector<int> dp(n, 0);
        for (char c : s) {
            int digit = c - '0';
            std::vector<int> next_dp = dp;
            next_dp[digit % n] = (next_dp[digit % n] + 1) % MOD;
            for (int r = 0; r < n; ++r) {
                if (dp[r] > 0) {
                    int newRem = (r * 10 + digit) % n;
                    next_dp[newRem] = (next_dp[newRem] + dp[r]) % MOD;
                }
            }
            dp = std::move(next_dp);
        }
        return dp[0];
    }
};
int main() {
    Solution sol;
    std::string s1 = "1234";
    int n1 = 4;
    std::cout << "Input: s = \"" << s1 << "\", n = " << n1 << "\n";
    std::cout << "Output: " << sol.countSubsequences(s1, n1) << " (Expected: 4)\n\n";
    std::string s2 = "330";
    int n2 = 6;
    std::cout << "Input: s = \"" << s2 << "\", n = " << n2 << "\n";
    std::cout << "Output: " << sol.countSubsequences(s2, n2) << " (Expected: 4)\n";
    return 0;
}