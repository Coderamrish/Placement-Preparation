/*
Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.

Note: After skipping the element, the subarray must still be non-empty.

Examples:

Input: arr[] = [1, 2, 3, -4, 5]
Output: 11
Explanation: We can get maximum sum subarray by skipping -4.
Input: arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 9
Explanation: We can get maximum sum subarray by skipping -2 as [4,-1,1,5] sums to 9, which is the maximum achievable sum.
Constraints:
1 ≤ arr.size() ≤ 106
-103 ≤ arr[i] ≤ 103

Approach - using dp constant approach one pass Initialize:
noDel = arr[0] -> max subarray sum ending at index i (no deletion state)
oneDel = 0 -> max subarray sum with at most one deletion allowed
ans = arr[0] -> stores global maximum
Traverse array from i = 1 to n-1.
Step 1: Update oneDel (deletion-aware state)
Either extend previous oneDel with current element --> oneDel + arr[i]
OR take noDel (switching state effect).
So, oneDel = max(noDel, oneDel + arr[i])
Step 2: Update noDel (no-deletion Kadane state)
Either start new subarray at arr[i] OR extend previous noDel.
So, noDel = max(arr[i], noDel + arr[i])
Step 3: Update answer, ans = max(ans, max(noDel, oneDel))
Return ans
TC:O(n) SC:O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    if(!(cin >> N)) return 0;
    int first_element;
    cin >> first_element;
    int noDel = first_element, oneDel = 0, ans = first_element;
    for(int i = 1; i < N; i++) {
        int current;
        cin >> current;
        int next_oneDel = max(noDel, oneDel + current);
        int next_noDel = max(current, noDel + current);
        oneDel = next_oneDel;
        noDel = next_noDel;
        ans = max(ans, max(noDel, oneDel));
    }
    cout << ans;
    return 0;
}
