/*
Given a sorted array of integers and a key, perform Binary Search.

If the key is found, print the key.
Otherwise, print the element whose value is closest (minimum absolute difference) to the key.
If two elements are equally close, print the smaller element.
Input Format
The first line contains an integer N, representing the number of elements in the array.
The second line contains N space-separated integers in sorted order.
The third line contains an integer K, representing the key to search.
Output Format
Print the key if it exists in the array.
Otherwise, print the element whose value is closest to the key.
If two elements are equally close, print the smaller element.
Constraints
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i], K ≤ 10^9
The array is sorted in non-decreasing order.
Example 1

Input

6
1 3 5 7 9 11
7

Output

7

Explanation
The key 7 is present in the array, so print 7.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    long long K;
    cin >> K;
    int low = 0, high = N - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == K) {
            cout << arr[mid] << "\n";
            return 0;
        }
        if (arr[mid] < K)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (high < 0) {
        cout << arr[0] << "\n";
    } else if (low >= N) {
        cout << arr[N - 1] << "\n";
    } else {
        long long diff1 = abs(arr[high] - K);
        long long diff2 = abs(arr[low] - K);
        if (diff1 <= diff2) {
            cout << arr[high] << "\n";
        } else {
            cout << arr[low] << "\n";
        }
    }
    return 0;
}