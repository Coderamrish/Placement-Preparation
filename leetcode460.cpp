/*
You are given an integer array nums.

Your task is to find the number of pairs of non-empty subsequences (seq1, seq2) of nums that satisfy the following conditions:

The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
Return the total number of such pairs.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4]

Output: 10

Explanation:

The subsequence pairs which have the GCD of their elements equal to 1 are:

([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
Example 2:

Input: nums = [10,20,30]

Output: 2

Explanation:

The subsequence pairs which have the GCD of their elements equal to 10 are:

([10, 20, 30], [10, 20, 30])
([10, 20, 30], [10, 20, 30])
Example 3:

Input: nums = [1,1,1,1]

Output: 50

 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 200
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD = 1000000007;
const int MAXG = 200;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i  = 0; i < N; i++) 
        cin >> nums[i];
vector<vector<int>> dp(MAXG + 1, vector<int>(MAXG + 1, 0));
dp[0][0] = 1;
for(int x : nums) {
    vector<vector<int>> ndp = dp;
    for(int g1 = 0; g1 <= MAXG; g1++) {
        for(int g2 = 0; g2 <= MAXG; g2++) {
            if(dp[g1][g2] == 0) 
            continue;
            int ng1 = (g1 == 0) ? x : __gcd(g1, x);
int ng2 = (g2 == 0) ? x : __gcd(g2, x);
ndp[ng1][g2] += dp[g1][g2];
if(ndp[ng1][g2] >= MOD)
ndp[ng1][g2] -= MOD;
ndp[g1][ng2] += dp[g1][g2];
if(ndp[g1][ng2] >= MOD)
ndp[g1][ng2] -= MOD;
        }
    }
    dp=ndp;
}
long long ans = 0;
for(int g = 1; g <= MAXG; g++) {
    ans = (ans + dp[g][g]) % MOD;
}
cout << ans;
return 0;
}
