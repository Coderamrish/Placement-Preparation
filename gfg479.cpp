/*
Given an array arr[] and an integer k, find the maximum sum among all contiguous subarrays having a length greater than or equal to k.
Examples:
Input: arr[] = [1, -2, 2, -3], k = 3
Output: 1
Explanation: The sub-array of length at least 3 that produces greatest sum is [1, -2, 2]
Input: arr[] = [1, 1, 1, 1, 1, 1], k = 2
Output: 6
Explanation: The sub-array of length at least 2 that produces greatest sum is [1, 1, 1, 1, 1, 1]
Input: arr[] = [-4, -2, 1, -3], k = 2
Output: -1
Explanation: The sub-array of length at least 2 that produces greatest sum is [-2, 1]
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
1 ≤ k ≤ arr.size()
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxSumWithK(vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    int last = 0;
    int j = 0;
    int maxSum = sum;
    for (int i = k; i < n; i++) {
        sum += arr[i];
        last += arr[j++];
        if (last < 0) {
            sum -= last;
            last = 0;
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSumWithK(arr, k);
    return 0;
}