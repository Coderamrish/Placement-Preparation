/*
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
 

Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= li < ri <= 105
All the given intervals are unique.
Approach - sorting and greedy TC:O(n log n) SC:O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;  
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    int count = 0;
    int maxEnd = 0;
    for (auto &it : intervals) {
        if (it[1] > maxEnd) {
            count++;
            maxEnd = it[1];
        }
    }
    cout << count << "\n";
    return 0;
}