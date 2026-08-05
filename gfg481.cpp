/*
Given an integer array arr[] and two integers l and r, find the number of subarrays whose sum lies in the range [l, r] (inclusive).

A subarray is a contiguous sequence of elements within the array.

Examples:

Input: l = 3, r = 8, arr[] = [1, 4, 6]
Output: 3
Explanation: The subarrays are [1,4], [4] and [6]. Therefore answer for this test case is 3.
Input: l = 4, r = 13, arr[] = [2, 3, 5, 8]
Output: 6
Explanation: The subarrays are [2, 3], [2, 3, 5], [3, 5], [5], [5, 8] and [8]. 
Therefore answer for this test case is 6.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
1 ≤ l ≤ r ≤ 109
*/
#include <iostream>
#include <vector>
using namespace std;
int countSub(vector<int> &arr, int x)
{
    int n = arr.size();
    int st = 0;
    int end = 0;
    int sum = 0;
    int cnt = 0;
    while (end < n)
    {
        sum += arr[end];
        while (st <= end && sum > x)
        {
            sum -= arr[st];
            st++;
        }
        cnt += (end - st + 1);
        end++;
    }
    return cnt;
}
int countSubarray(vector<int> &arr, int l, int r)
{
    int rcnt = countSub(arr, r);
    int lcnt = countSub(arr, l - 1);
    return rcnt - lcnt;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l, r;
    cin >> l >> r;
    cout << countSubarray(arr, l, r);
    return 0;
}