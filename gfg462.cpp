/*
Given an array of integers arr[], find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-arrays is maximum.

Examples :

Input: arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 12
Explanation: Two subarrays are [-2, -3] and [4, -1, -2, 1, 5]
Input: arr[] = [2, -1, -2, 1, -4, 2, 8]
Output: 16
Explanation: Two subarrays are [-1, -2, 1, -4] and [2, 8] 
Constraints:
2 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103
Approach - to solve this problem in the most optimal way we can use the kadane's algorithm with the array inversion where the tc:O(n) SC:O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
vector<int> buildleftmax(vector<int>& arr) {
    int n = arr.size();
    vector<int> leftmax(n);
    int curr = arr[0];
    int best = arr[0];
    leftmax[0] = best;
    for(int i = 1; i < n; i++) {
        curr = max(arr[i], curr+arr[i]);
        best = max(best, curr);
        leftmax[i] = best;
    }
    return leftmax;
}
vector<int> buildrightmax(vector<int>& arr) {
    int n = arr.size();
    vector<int> rightmax(n);
    int curr = arr[n - 1];
    int best = arr[n - 1];
    rightmax[n - 1] = best;
    for(int i = n - 2; i >= 0; i--) {
        curr = max(arr[i], curr+arr[i]);
        best = max(best, curr);
        rightmax[i] = best;
    }
    return rightmax;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n)) return 0;
    vector<int> arr(n);
    for(int i =0; i < n; i++) {
        cin >> arr[i];
    }
    if(n < 2) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int>leftmax = buildleftmax(arr);
    vector<int> rightmax = buildrightmax(arr);
    vector<int> inverted(arr);
    for(int &x: inverted) x = -x;
    vector<int> leftmin = buildleftmax(inverted);
    vector<int> rightmin = buildrightmax(inverted);
    for(int &x : leftmin) x = -x;
    for(int &x : rightmin) x = -x;
    int maxDiff = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        int option1 = abs(leftmax[i] - rightmin[i+1]);
int option2 = abs(leftmin[i] - rightmax[i+1]);
maxDiff = max({maxDiff, option1, option2});
    }
    cout << maxDiff << "\n";
    return 0;
}