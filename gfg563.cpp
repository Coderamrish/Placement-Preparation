/*
You are given an array arr[] of size n. You need to remove a subarray of size k , such that the difference between the maximum and minimum values of the remaining array is minimized. Find the minimum value obtained after performing the operation of the removal of the subarray.
Examples:
Input: arr = [1, 2, 3, 4, 5], k = 3 
Output: 1
Explanation: We remove first subarray of length 3, the remaining array is [4,5] and the difference of maximum and minimum element is 1 i.e 5 - 4 = 1
Input: arr = [2, 3, 1, 4, 6, 7], k = 3
Output: 2
Explanation: 
If we remove the subarray [2,3,1] then remaining array is [4,6,7] and the difference  = 7-4 = 3
If we remove the subarray [3,1,4] then remaining array is [2,6,7] and the difference  = 7-2 = 5
If we remove the subarray [1,4,6] then remaining array is [2,3,7] and the difference  = 7-2 = 5
If we remove the subarray [4,6,7] then remaining array is [2,3,1] and the difference  = 3-1 = 2
So the answer is min(3,5,5,2) = 2
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 109
0 ≤ k < arr.size()
*/
#include <iostream>
#include <vector>
using namespace std;
int minDiff(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<int> suffixMax(n);
    vector<int> suffixMin(n);
    suffixMax[n - 1] = arr[n - 1];
    suffixMin[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(arr[i], suffixMax[i + 1]);
        suffixMin[i] = min(arr[i], suffixMin[i + 1]);
    }
    int res = suffixMax[k] - suffixMin[k];
    int prefixMax = arr[0];
    int prefixMin = arr[0];
    for (int i = 1; i < n - k; i++)
    {
        int currentMax = max(prefixMax, suffixMax[i + k]);
        int currentMin = min(prefixMin, suffixMin[i + k]);
        res = min(res, currentMax - currentMin);
        prefixMax = max(prefixMax, arr[i]);
        prefixMin = min(prefixMin, arr[i]);
    }
    res = min(res, prefixMax - prefixMin);
    return res;
}
int main()
{
    vector<int> arr = {2, 3, 1, 4, 6, 7};
    int k = 3;
    cout << minDiff(k, arr) << endl;
    return 0;
}