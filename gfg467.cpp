/*
Given an array arr[], find the minimum number of elements to delete so that the remaining elements form a strictly increasing sequence in the same order.

Examples:

Input: arr[] = [5, 6, 1, 7, 4]
Output: 2
Explanation: Removing 1 and 4 leaves [5, 6, 7] which is strictly increasing.
Input: arr[] = [1, 1, 1]
Output: 2
Explanation: Removing any 2 elements leaves [1] which is strictly increasing.
Constraints:
1 ≤ n ≤ 105 
1 ≤ arr[i] ≤ 105
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> tails;
    for(int i = 0; i < n; i++) {
    int lo = 0, high = tails.size() - 1;
    while(lo <= high) {
        int mid = lo + (high - lo) / 2;
if(tails[mid] < arr[i])
lo = mid + 1;
else
high = mid - 1;
    }
    if(lo == tails.size())
    tails.push_back(arr[i]);
    else
    tails[lo] = arr[i];
    }
    cout << n - tails.size();
    return 0;
}