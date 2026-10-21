/*
Given an array arr[], find the minimum sum of a subarray containing atleast one element in the given array.

Examples:

Input: arr[] = [3, -4, 2, -3, -1, 7, -5]
Output: -6
Explanation: The subarray [-4, 2, -3, -1] has the minimum sum, which is -6.
Input: arr[] = [4, -6, 3, -2, 5, -8, 2]
Output: -8
Explanation: The subarray [-8] has the minimum sum, which is -8.
Input: arr[] = [2, 6, 8, 1, 4]
Output: 1
Explanation: The subarray [1] has the minimum sum, which is 1.
Constraints:

1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
*/
#include <iostream>
#include<climits>
#include<vector>
using namespace std;
int minSubarraySum(vector<int>&arr)
{
    int n=arr.size();
    int curMin = INT_MAX;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (curMin > 0)
            curMin = arr[i];
        else
            curMin += arr[i];
        ans = min(ans, curMin);
    }
    return ans; 
}
int main()
{
    vector<int>arr = {3, -4, 2, -3, -1, 7, -5};
    cout << minSubarraySum(arr);
    return 0;
}