/*
Given a number n, count the numbers from 1 to n that don’t contain digit d in their decimal representation.

Examples:

Input: n = 25, d = 3
Output: 22
Explanation: From 1 to 25, the numbers 3, 13, and 23 contain the digit 3, so the answer is 25 - 3 = 22.
Input: n = 5, d = 3
Output: 4
Explanation: From 1 to 5, only 3 contains the digit 3, so the count of numbers without digit 3 is 4.
Constraints:

0 ≤ n ≤ 109
0 ≤ d ≤ 9
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    int countWithout(int n, int d) {
        if (n <= 0)
            return 0;
        string s = to_string(n);
        int len = s.length();
        int dp[2][2] = {};
        dp[0][1] = 1;
        dp[1][1] = 1;
        for (int pos = len - 1; pos >= 0; pos--) {
            int newDp[2][2] = {};
            for (int tight = 0; tight <= 1; tight++) {
                for (int started = 0; started <= 1; started++) {
                    int limit = tight ? (s[pos] - '0') : 9;
                    for (int digit = 0; digit <= limit; digit++) {
                        if ((started || digit != 0) && digit == d)
                            continue;
                        int newStarted = started || (digit != 0);
                        int newTight =
                            tight && (digit == (s[pos] - '0'));
                        newDp[newTight][newStarted] +=
                            dp[tight][started];
                    }
                }
            }
            memcpy(dp, newDp, sizeof(dp));
        }
        return dp[0][1] + dp[1][1];
    }
};
int main() {
    int n, d;
    cin >> n >> d;
    Solution obj;
    cout << obj.countWithout(n, d);
    return 0;
}