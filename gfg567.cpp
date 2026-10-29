/*
Given an array arr[] of integers and a range [l, r], count the number of subsets whose Minimum Excluded (MEX) value lies within the given range, inclusive.
Minimum Excluded (or MEX) of a subset is the smallest non-negative integer that is not present in the subset.
An empty subset has Minimum Excluded as zero.
Since the answer can be very large, return the answer modulo 109 + 7.
Examples:
Input: arr[] = [2, 0, 1, 0], l = 1, r = 2
Output: 9
Explanation: The subsets whose MEX lies in the range [1, 2] are counted as follows:
MEX = 1: The subsets must contain at least one 0 and must not contain 1. These subsets are [0] (2 ways), [2, 0] (2 ways), [0, 0] (1 way), and [2, 0, 0] (1 way). Total = 6.
MEX = 2: The subsets must contain both 0 and 1 but must not contain 2. These subsets are [0, 1] (2 ways) and [0, 1, 0] (1 way). Total = 3.
The subsets [2, 0, 1] and [2, 0, 1, 0] have MEX = 3, which is outside the given range. Therefore, the total number of valid subsets is 6 + 3 = 9.
Input: arr[] = [2, 0, 1], l = 1, r = 2
Output: 3
Explanation: The subsets whose MEX lies in the range [1, 2] are [0] (MEX = 1), [2, 0] (MEX = 1), and [0, 1] (MEX = 2). Hence, the answer is 3.
Constraints:
2 ≤ arr.size() ≤ 105
0 ≤ arr[i], r ≤ arr.size()
0 ≤ l ≤ r
*/
#include <bits/stdc++.h>
using namespace std;
int cntSubsets(vector<int> &arr, int l, int r)
{
    const long long M = 1000000007;
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int num : arr)
    {
        mp[num]++;
    }
    vector<long long> power(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        power[i] = (power[i - 1] * 2) % M;
    }
    long long res = 0;
    long long cur = 1;
    int seen = 0;
    for (int i = 0; i < l; i++)
    {
        int freq = mp[i];
        if (freq == 0)
        {
            return 0;
        }
        seen += freq;
        cur = (cur * (power[freq] - 1 + M)) % M;
    }
    for (int i = l; i <= r; i++)
    {
        int freq = mp[i];
        long long here = (cur * power[n - seen - freq]) % M;
        res = (res + here) % M;
        if (freq == 0)
        {
            return res;
        }
        seen += freq;
        cur = (cur * (power[freq] - 1 + M)) % M;
    }
    return (int)res;
}
int main()
{
    vector<int> arr = {2, 0, 1, 0};
    int l = 1, r = 2;
    cout << cntSubsets(arr, l, r) << "\n";
    return 0;
}