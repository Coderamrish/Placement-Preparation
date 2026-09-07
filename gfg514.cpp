/*
Given an array arr[] of size n, partition its elements into a strictly increasing subsequence and a strictly decreasing subsequence.

Each element can belong to at most one of these subsequences, and some elements may remain unused.

Determine the minimum number of elements that cannot be included in either subsequence.

Examples:

Input: arr[] = [7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7]
Output: 2
Explanation: One possible increasing subsequence is: [1, 2, 4, 5, 8]. One possible decreasing subsequence is: [7, 6, 3, 2, 1]. The remaining elements are 8 and 7, so the minimum number of unselected elements is 2.
Input: arr[] = [1, 4, 2, 3, 3, 2, 4]
Output: 0
Explanation: One possible increasing subsequence is: [1, 2, 3, 4]. One possible decreasing subsequence is: [4, 3, 2]. All elements are included in one of the two subsequences.
Constraints:
1 ≤ n ≤ 100
1 ≤ arr[i] ≤ 100
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> next(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> curr(n + 1, vector<int>(n + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int incLast = -1; incLast < n; incLast++) {
                for (int decLast = -1; decLast < n; decLast++) {
                    int ans = 1 + next[incLast + 1][decLast + 1];
                    if (incLast == -1 || arr[idx] > arr[incLast]) {
                        ans = min(
                            ans,
                            next[idx + 1][decLast + 1]
                        );
                    }
                    if (decLast == -1 || arr[idx] < arr[decLast]) {
                        ans = min(
                            ans,
                            next[incLast + 1][idx + 1]
                        );
                    }
                    curr[incLast + 1][decLast + 1] = ans;
                }
            }
            next = curr;
        }
        return next[0][0];
    }
};
int main() {
    Solution sol;
    vector<int> arr = {5, 1, 3, 2, 4};
    cout << sol.minCount(arr) << endl;
    return 0;
}