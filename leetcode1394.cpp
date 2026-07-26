/*
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
Return the largest lucky integer in the array. If there is no lucky integer return -1.
Example 1:
Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:
Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:
Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
Constraints:
1 <= arr.length <= 500
1 <= arr[i] <= 500
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int luckyNumber(vector<int> & arr) {
    int cnt[501] = {0};
    for(int num : arr) {
        cnt[num]++;
    }
    for(int i = 500; i >= 1; i--) {
        if(cnt[i] == i) return i;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << luckyNumber(arr) << "\n";
    return 0;
}