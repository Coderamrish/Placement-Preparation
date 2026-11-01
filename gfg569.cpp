/*
Given an integer array arr[], find the maximum subarray sum by squaring at most one element.
Examples:
Input: arr[] =  [-1, -2, 3, -2, 3]
Output: 10
Explanation: The subarray {3, -2, 3} with squaring -2 will give the maximum sum as 3 + 4 + 3 = 10.
Input: arr[] =  [-4, -4, -2, 5, 2, -1]
Output: 27
Explanation: The subarray {5, 2} with squaring 5 will give a maximum sum of 25 + 2 = 27.
Constraints:
1 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103
*/
#include <iostream>
#include <vector>
using namespace std;
int maximumSubarray(vector<int> &arr)
{
    int res = 0;
    int n = arr.size();
    vector<int> left(n + 1, 0);
    vector<int> right(n + 2, 0);
    int maxEndingHere = 0;
    for (int i = 0; i < n; i++)
    {
        maxEndingHere += arr[i];
        if (maxEndingHere < 0)
            maxEndingHere = 0;
        left[i + 1] = maxEndingHere;
    }
    maxEndingHere = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        maxEndingHere += arr[i];
        if (maxEndingHere < 0)
            maxEndingHere = 0;
        right[i + 1] = maxEndingHere;
    }
    for (int i = 1; i <= n; i++)
    {
        res = max(res, arr[i - 1] * arr[i - 1] + left[i - 1] + right[i + 1]);
    }
    return res;
}
int main()
{
    vector<int> arr = {-4, -4, -2, 5, 2, -1};
    cout << maximumSubarray(arr) << endl;
    return 0;
}