/*
Given two integers n  and k, consider an alphabet consisting of the first k lowercase English letters. Find the number of palindromic strings whose length is less than or equal to n, such that:
Every character in the string belongs to the given alphabet.
No character appears more than twice in the string.
Note: Since the answer can be very large, return it modulo 10^9+7.
Examples:
Input: n = 3, k = 2
Output: 6
Explanation: The possible strings are: "a", "b", "aa", "bb", "aba", "bab".
Input: n = 4, k = 3
Output: 18
Explanation: The possible strings are:"a", "b", "c", "aa", "bb", "cc", "aba", "aca", "bab", "bcb", "cac", "cbc", "abba", "acca", "baab", "bccb", "caac", "cbbc". 
Constraints:
1 ≤ k ≤ 26
1 ≤ n ≤ 52
n ≤ 2*k
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;
        vector<vector<long long>> nPr(k + 1, vector<long long>(k + 1, 0));
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    nPr[i][j] = 1;
                } else {
                    nPr[i][j] = (
                        nPr[i - 1][j] +
                        (j * nPr[i - 1][j - 1]) % MOD
                    ) % MOD;
                }
            }
        }
        long long res = 0;
        for (int i = 1; i <= n / 2; i++) {
            res = (res + nPr[k][i]) % MOD;
        }
        res = (res * 2) % MOD;
        if (n & 1) {
            res = (res + nPr[k][n / 2 + 1]) % MOD;
        }
        return (int)res;
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    Solution obj;
    cout << obj.palindromicStrings(n, k) << endl;
    return 0;
}