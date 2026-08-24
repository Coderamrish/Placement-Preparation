/*
Given an integer n, count the number of binary strings of length 2 * n that contain exactly n ones and n zeros such that every prefix of the string contains at least as many ones as zeros. Since the answer can be very large, return it modulo 109 + 7.
Examples:
Input: n = 2
Output: 2
Explanation: "1100", "1010" are two such strings of size 4 which have exactly two 1's in each.
Input: n = 3
Output: 5
Explanation: "111000", "101100", "101010", "110010", "110100" are such 5 strings which have exactly three 1's in each.
Constraints:
1 ≤ n ≤ 1000
*/
#include <iostream>
using namespace std;
class Solution {
public:
    long long power(long long a, long long b, int mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int prefixStrings(int n) {
        const int mod = 1000000007;
        long long catalan = 1;
        for (int i = 1; i <= n; i++) {
            catalan = (catalan * (2LL * (2 * i - 1))) % mod;
            catalan = (catalan * power(i + 1, mod - 2, mod)) % mod;
        }
        return (int)catalan;
    }
};
int main() {
    Solution obj;
    int n;
    cin >> n;
    cout << obj.prefixStrings(n) << endl;
    return 0;
}