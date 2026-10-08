/*
Given an integer array arr[]. In one operation, you can choose an index and increment its value by 1.
Find the maximum possible frequency of any element after performing at most k operations.
Examples:
Input: arr[] = [2, 2, 4], k = 4
Output: 3
Explanation: Apply two increment operations on index 0 and two operations on index 1 to make arr[]= [4, 4, 4]. Frequency of 4 is 3.
Input: arr[] = [7, 7, 7, 7], k = 5
Output: 4
Explanation: The frequency of 7 is already 4, so no operations are needed.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
0 ≤ k ≤ 105
*/
#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int maxFrequency(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    long long windowSum = 0;
    int left = 0;
    int res = 1;
    for (int right = 0; right < arr.size(); ++right) {
        windowSum += arr[right];
        while (1LL * arr[right] * (right - left + 1) - windowSum > k) {
            windowSum -= arr[left];
            ++left;
        }
        res = max(res, right - left + 1);
    }
    return res;
}
int main() {
    vector<int> arr1 = {2, 2, 4};
    int k1 = 4;
    cout << maxFrequency(arr1, k1) << '\n';
    vector<int> arr2 = {7, 7, 7, 7};
    int k2 = 5;
    cout << maxFrequency(arr2, k2) << '\n';
    return 0;
}