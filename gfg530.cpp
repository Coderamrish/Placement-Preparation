/*
Given an array arr[] consisting of stones, where arr[i] represents the height of the i-th stone.
You need to transform the stones into a pyramid by only reducing the heights of the stones. Reducing the height of a stone by 1 costs 1 unit, and stones cannot be increased or moved.
A valid pyramid consists of a contiguous subarray whose heights follow the pattern: 1, 2, 3, ..., x - 1, x, x - 1, ..., 2, 1 for some positive integer x.
Every stone outside this subarray must have a height of 0.
Find the minimum total cost required to build a pyramid. It is guaranteed that at least one valid pyramid can always be formed.
Examples:
Input: arr[] = [1, 2, 3, 4, 2, 1]
Output: 4
Explanation: We can obtain the array [1, 2, 3, 2, 1, 0] by subtracting 2 out of 4, 1 out of 2, and 1 out of 1. In total, we will subtract 4.
Input: arr[] = [1, 2, 1]
Output: 0
Explanation: The array is already in pyramid form.
Constraints:
1 ≤ arr.size(), arr[i] ≤ 105
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int formPyramid(vector<int> &arr)
{
    int n = arr.size();
    int totalHeight = 0;
    for (int i = 0; i < n; i++)
        totalHeight += arr[i];
    if (n <= 2)
        return totalHeight - 1;
    vector<int> left(n), right(n);
    left[0] = 1;
    for (int i = 1; i < n; i++)
        left[i] = min(left[i - 1] + 1, arr[i]);
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        right[i] = min(right[i + 1] + 1, arr[i]);
    int minCost = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int peakHeight = min(left[i], right[i]);
        int pyramidSum = peakHeight * peakHeight;
        minCost = min(minCost, totalHeight - pyramidSum);
    }
    return minCost;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 2, 1};
    cout << formPyramid(arr) << endl;
    return 0;
}