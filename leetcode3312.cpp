/*
You are given an integer array nums of length n and an integer array queries.

Let gcdPairs denote an array obtained by calculating the GCD of all possible pairs (nums[i], nums[j]), where 0 <= i < j < n, and then sorting these values in ascending order.

For each query queries[i], you need to find the element at index queries[i] in gcdPairs.

Return an integer array answer, where answer[i] is the value at gcdPairs[queries[i]] for each query.

The term gcd(a, b) denotes the greatest common divisor of a and b.

 

Example 1:

Input: nums = [2,3,4], queries = [0,2,2]

Output: [1,2,2]

Explanation:

gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1].

After sorting in ascending order, gcdPairs = [1, 1, 2].

So, the answer is [gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2].

Example 2:

Input: nums = [4,4,2,1], queries = [5,3,1,0]

Output: [4,2,1,1]

Explanation:

gcdPairs sorted in ascending order is [1, 1, 1, 2, 2, 4].

Example 3:

Input: nums = [2,2], queries = [0,0]

Output: [2,2]

Explanation:

gcdPairs = [2].

 

Constraints:

2 <= n == nums.length <= 105
1 <= nums[i] <= 5 * 104
1 <= queries.length <= 105
0 <= queries[i] < n * (n - 1) / 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q_size;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    int maxNum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }
    if (!(cin >> q_size)) return 0;
    vector<long long> queries(q_size);
    for (int i = 0; i < q_size; i++) {
        cin >> queries[i];
    }
    vector<int> countDivisor(maxNum + 1, 0);
    for (int num : nums) {
        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                countDivisor[i]++;
                if (i * i != num) {
                    countDivisor[num / i]++;
                }
            }
        }
    }
    vector<long long> countGcdPair(maxNum + 1, 0);
    for (int gcd = maxNum; gcd >= 1; --gcd) {
        long long c = countDivisor[gcd];
        countGcdPair[gcd] = c * (c - 1) / 2;
        for (int multiple = 2 * gcd; multiple <= maxNum; multiple += gcd) {
            countGcdPair[gcd] -= countGcdPair[multiple];
        }
    }
    vector<long long> prefixCountGcdPair(maxNum + 1, 0);
    for (int i = 1; i <= maxNum; ++i) {
        prefixCountGcdPair[i] = prefixCountGcdPair[i - 1] + countGcdPair[i];
    }
    for (int i = 0; i < q_size; i++) {
        long long query = queries[i];
        auto it = upper_bound(prefixCountGcdPair.begin(), prefixCountGcdPair.end(), query);
        int ans = distance(prefixCountGcdPair.begin(), it);  
        cout << ans << (i == q_size - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}