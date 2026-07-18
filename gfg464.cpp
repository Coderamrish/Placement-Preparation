/*
Given an array arr[] and a list of queries. For each query [l, r], find whether the subarray arr[l...r] is a mountain array. A subarray is called a mountain array if there exists an index k (l ≤ k ≤ r) such that: arr[l] ≤ arr[l + 1] ≤ ... ≤ arr[k] ≥ arr[k + 1] ≥ ... ≥ arr[r].

Elements of a Mountain subarray are first non-decreasing and then non-increasing.
A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.
Examples:

Input: arr[] = [2, 3, 2, 4, 4, 6, 3, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, false]
Explanation: For query [0, 2], the subarray is [2, 3, 2]. The elements first increase and then decrease, so it forms a mountain.
For query [1, 3], the subarray is [3, 2, 4]. The elements decrease and then increase, so it does not form a mountain.
Input: arr[] = [2, 2, 2, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, true]
Explanation: All subarrays of the given array are mountain.
Constraints:
1 <= arr.size(), queries.size() <= 105
1 <= arr[i] <= 106
0 <= l <= r < arr.size()
*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
void precompute(const vector<int>& arr, vector<int>& left, vector<int>& right, int n) {
    // left[i] stores the index of the last element that is <= arr[i] continuously from the left
    left[0] = 0;
    int last_incr = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            last_incr = i;
        }
        left[i] = last_incr;
    }
    right[n - 1] = n - 1;
    int first_decr = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            first_decr = i;
        }
        right[i] = first_decr;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> left(n), right(n);
    precompute(arr, left, right, n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (right[l] >= left[r]) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }
    return 0;
}