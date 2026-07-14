/*
Given an array arr[] of size n containing positive integers, return the maximum length of the bitonic subarray.

A subarray arr[i...j] is considered bitonic if its elements first monotonically increase, and then monotonically decrease. Formally, there exists and index k (where i <= k <= j) such that:

arr[i] <= arr[i+1] <= . . . <= arr[k] 
arr[k] >= arr[k+1] >= . . . >= arr[j]
Examples: 

Input: arr[] = [12, 4, 78, 90, 45, 23]
Output: 5
Explanation: The longest bitonic subarray is [4, 78, 90, 45, 23], it starts increasing at 4, peaks at 90, and decreases to 23, giving length of 5.
Input: arr[] = [10, 20, 30, 40]
Output: 4
Explanation: The array [10, 20, 30, 40] is striclty increasing with no decreasing part, so longest bitonic subarray is the entire array itself, giving a length of 4.
Input: arr[] = [10, 10, 10, 10]
Output: 4
Constraints:
1 ≤  n ≤ 106
1 ≤ arr[i] ≤ 106
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longestSubarray(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    int maxLen = 1;
    int start = 0;
    int nextStart = 0;
    int j = 0;
    while(j < n - 1) {
        while(j < n - 1 && arr[j] <= arr[j + 1]) 
        j++;
        while(j < n - 1 && arr[j] >= arr[j + 1]) {
        if(arr[j] > arr[j + 1]) 
        nextStart = j + 1;
        j++;
    }
    maxLen = max(maxLen, j - start + 1);
    start = nextStart;
}
return maxLen;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << longestSubarray(arr);
    return 0;
}