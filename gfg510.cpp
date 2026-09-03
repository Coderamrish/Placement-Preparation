/*
Given an integer array arr[], you are allowed to replace any elements with 1.  Find the maximum sum of absolute differences between consecutive elements after any number of modifications.

Examples:
Input: arr[] = [3, 2, 1, 4, 5]
Output: 8
Explanation: Modify the array as arr[] = [3, 1, 1, 4, 1]. 
Sum = |1-3| + |1-1| + |4-1| + |1-4| = 8, the maximum possible.
Input: arr[] = [1, 5]
Output: 4
Explanation: No modification needed. Sum = |5-1| = 4.
Constraints:
1 ≤ arr.size() ≤ 105
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for (int i = 0; i < n - 1; i++) {
            dp[i + 1][0] = max(
                dp[i][0],
                dp[i][1] + abs(1 - arr[i])
            );
            dp[i + 1][1] = max(
                dp[i][0] + abs(arr[i + 1] - 1),
                dp[i][1] + abs(arr[i + 1] - arr[i])
            );
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, 5, 2, 9};
    cout << sol.maxDiffSum(arr) << endl;
    return 0;
}