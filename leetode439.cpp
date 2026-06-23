/*
You are given three integers n, l, and r.

A ZigZag array of length n is defined as follows:

Each element lies in the range [l, r].
No two adjacent elements are equal.
No three consecutive elements form a strictly increasing or strictly decreasing sequence.
Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo 109 + 7.

A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

Example 1:

Input: n = 3, l = 4, r = 5

Output: 2

Explanation:

There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

[4, 5, 4]
[5, 4, 5]​​​​​​​
Example 2:

Input: n = 3, l = 1, r = 3

Output: 10

Explanation:

There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

[1, 2, 1], [1, 3, 1], [1, 3, 2]
[2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
[3, 1, 2], [3, 1, 3], [3, 2, 3]
All arrays meet the ZigZag conditions.

 

Constraints:

3 <= n <= 2000
1 <= l < r <= 2000
approach - we can use dp to solve it To solve this problem efficiently, we can use Dynamic Programming.Instead of tracking the exact values in the range [l, r], we only care about their relative size. Thus, we can map the range [l, r] to [1, k] where $k = r - l + 1$.A ZigZag array alternates directions. To avoid three consecutive increasing or decreasing elements, if the previous step was an "increase", the next step must be a "decrease", and vice versa.
TC:O(n . k) SC:O(k)
*/
#include<iostream>
#include<vector>
using namespace std;
int zigZagArrays(int n, int l ,int r) {
    int k = r - l + 1;
    int MOD = 1e9 + 7;
    vector<int> up(k+2, 0);
    vector<int> down(k + 2, 0);
    for(int j = 1; j <= k; j++) {
        up[j] = j - 1;
        down[j] = k - j;
    }
    for(int i = 3; i <= n; ++i) {
        vector<int> next_up(k+ 2 , 0);
        vector<int> next_down(k + 2, 0);
        for(int j = 1; j <= k; ++j) {
            next_up[j] = (next_up[j - 1] + down[j - 1]) % MOD;
        }
        for(int j = k; j >= 1; --j) {
            next_down[j] = (next_down[j + 1]+ up[j + 1]) % MOD;
        }
        up = next_up;
        down = next_down;
    }
    int ans = 0;
    for(int j = 1; j <= k; ++j) {
        ans = (ans + up[j]) % MOD;
        ans = (ans + down[j]) % MOD;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r;
  cin >> n >> l >> r;
    cout << zigZagArrays(n,l,r) << "\n";

return 0;
}