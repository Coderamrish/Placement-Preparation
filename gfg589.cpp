/*
Given an integer x and an array of integers, arr[]. Find the length of the smallest subarray whose sum is strictly greater than x.
If no such subarray exists, return 0.
Examples:
Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: The smallest subarray with a sum greater than 51 is [4, 45, 6], whose sum is 55 and length is 3.
Input: x = 100, arr[] = [1, 10, 5, 2, 7]
Output: 0
Explanation: No subarray has a sum greater than 100. Hence, the answer is 0.
Constraints:
1 ≤ x, arr.size() ≤ 105
0 ≤ arr[i] ≤ 104
*/

#include <bits/stdc++.h>
using namespace std;
int smallestSubWithSum(vector<int> &arr, int x)
{
    int n = arr.size();
    int res = INT_MAX;
    vector<int> preSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        preSum[i] = preSum[i - 1] + arr[i - 1];
    for (int i = 1; i <= n; i++)
    {
        int toFind = x + preSum[i - 1];
        auto bound = lower_bound(preSum.begin() + i, preSum.end(), toFind);
        if (bound != preSum.end() && *bound == toFind)
            bound = upper_bound(bound, preSum.end(), toFind);
        if (bound != preSum.end())
        {
            int len = bound - (preSum.begin() + i - 1);
            res = min(res, len);
        }
    }
    if (res == INT_MAX)
        return 0;
    return res;
}
int main()
{
    vector<int> arr = {1, 4, 45, 6, 10, 19};
    int x = 51;
    cout << smallestSubWithSum(arr, x);
    return 0;
}