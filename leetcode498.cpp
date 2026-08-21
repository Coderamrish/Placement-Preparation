/*
You are given an integer array coins representing coins of different denominations and an integer k.

You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.

Return the kth smallest amount that can be made using these coins.

 

Example 1:

Input: coins = [3,6,9], k = 3

Output: 9

Explanation: The given coins can make the following amounts:
Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
All of the coins combined produce: 3, 6, 9, 12, 15, etc.

Example 2:

Input: coins = [5,2], k = 7

Output: 12

Explanation: The given coins can make the following amounts:
Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.
Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.
All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14, 15, etc.

 

Constraints:

1 <= coins.length <= 15
1 <= coins[i] <= 25
1 <= k <= 2 * 109
coins contains pairwise distinct integers.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    long long countNumbers(long long x, vector<int>& coins) {
        int n = coins.size();
        long long total = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long common = 1;
            int bits = 0;
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    common = lcm(common, coins[i]);
                    if (common > x) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {
                continue;
            }
            long long cnt = x / common;
            if (bits % 2 == 1) {
                total += cnt;
            }
            else {
                total -= cnt;
            }
        }
        return total;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high =
            1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (countNumbers(mid, coins) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.findKthSmallest(coins, k) << endl;
    return 0;
}