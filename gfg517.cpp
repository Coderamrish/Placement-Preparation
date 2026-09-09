/*
Given two integers x and y representing the GCD and LCM of two unknown positive integers a and b, count the number of valid pairs (a, b) satisfying these conditions. Note that (a, b) and (b, a) are counted as distinct pairs when a ≠ b.

Examples:

Input: x = 2, y = 12
Output: 4
Explanation: The valid pairs are (2, 12), (4, 6), (6, 4), and (12, 2), since each pair has GCD = 2 and LCM = 12.
Input: x = 6, y = 4
Output: 0
Explanation: LCM must always be a multiple of GCD. Since y is not divisible by x, no valid pair exists.
Constraints:
1 ≤ x, y ≤ 104
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pairCount(int x, int y) {
        int n = 0, res = 0;
        if (y % x == 0)
            n = y / x;
        if (n == 1)
            res = 1;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                int j = n / i;
                if (i != j && __gcd(x * i, x * j) == x)
                    res += 2;
            }
        }
        return res;
    }
};
int main() {
    int x, y;
    cin >> x >> y;
    Solution obj;
    cout << obj.pairCount(x, y) << endl;
    return 0;
}