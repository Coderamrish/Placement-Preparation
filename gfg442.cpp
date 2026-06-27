/*
Given a floor of dimensions n × m and an unlimited supply of tiles of size 1 × m, find the total number of ways to completely tile the floor.
Each tile can be placed in one of the following ways:

Horizontally, covering 1 row and m columns.
Vertically, covering m rows and 1 column.
Count all possible ways to cover the entire floor such that there are no overlaps and no uncovered cells.

Since the number of possible tilings can be very large, return the answer modulo 109+7.

Note: n and m are positive integers, and m ≥ 2.

Examples:

Input: n = 4, m = 4
Output: 2
Explanation: There are exactly two valid ways to tile the floor. 

Input: n = 2, m = 3
Output: 1
Explanation: Placing a tile vertically would require a height of 3, which exceeds the floor's height of 2. The only way to cover the entire floor is by placing 2 horizontally, one in each row, resulting in exactly one valid tiling. 
Constraints:
1 ≤ n ≤ 105
2 ≤ m ≤ 105
Approch we can solve it using the recursion where the tc :O(2^n) SC:O(n)
Approach 2 - we can also solve it using the Dp using the bottom up TC:O(n) SC:O(n)
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int countWays(int n, int m){
    int MOD = 1e9+7;
    vector<int>dp(n+1);
    for(int i = 0; i <= n; i++) {
        if(i < m) dp[i] = 1;
        else if(i == m) dp[i] = 2;
        else
        dp[i] = (dp[i-1]+dp[i-m])%MOD;
    }
    return dp[n];
}
int main() {
    int n, m;
    cin >> n >> m;
    cout << countWays(n,m)<< endl;
    return 0;
}