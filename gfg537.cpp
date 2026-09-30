/*
Geek is standing at a point (x, y) on a 2D grid and wants to reach the origin (0, 0).
From any point, Geek can move in only two directions: left, from (x, y) to (x - 1, y), or down, from (x, y) to (x, y - 1).
Find the total number of distinct paths for Geek to reach (0, 0) from (x, y). Since the answer can be very large, return it modulo 109+7.
Examples:
Input: x = 3, y = 0
Output: 1
Explanation: The only possible path is (3, 0) -> (2, 0) -> (1, 0) -> (0, 0), since y = 0, there is no option to move down at any step.
Input: x = 3, y = 6
Output: 84
Explanation: There are a total of 84 distinct paths from (3, 6) to (0, 0) using only left and down moves.
Constraints:
0 ≤ x, y ≤ 500
*/
#include <iostream>
#include <algorithm>
using namespace std;
long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1000000007;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
long long modInverse(long long n) {
    return power(n, 1000000007 - 2);
}
int ways(int x, int y) {
    long long mod = 1000000007;
    int n = x + y;
    int r = min(x, y);
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = (ans * (n - i + 1)) % mod;
        ans = (ans * modInverse(i)) % mod;
    }
    return (int)ans;
}
int main() {
    int x = 3, y = 6;
    cout << ways(x, y) << endl;
    return 0;
}