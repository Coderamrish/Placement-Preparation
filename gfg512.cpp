/*
Given an array arr[] with n elements. find the longest subsequence such that the absolute difference between adjacent elements is one.

Examples:

Input : arr[] = [10, 9, 4, 5, 4, 8, 6]
Output : 3
Explanation: Longest subsequences with difference 1 are [10, 9, 8], [4, 5, 4] and [4, 5, 6]. 
Input : arr[] = [1, 2, 3, 2, 3, 7, 2, 1]
Output : 7
Explanation:  Longest subsequences with difference 1 is [1, 2, 3, 2, 3, 2, 1]. 
Constraints:

1 ≤ arr.size(), arr[i] ≤ 106
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int longestSubseq(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) {
        return 1;
    }
    unordered_map<int, int> dp;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (dp.count(arr[i] + 1) > 0 ||
            dp.count(arr[i] - 1) > 0) {
            dp[arr[i]] = 1 + max(
                dp[arr[i] + 1],
                dp[arr[i] - 1]
            );
        }
        else {
            dp[arr[i]] = 1;
        }
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << longestSubseq(arr) << endl;
    return 0;
}