/*
Consider an input where all marks obtained are divided into intervals of consecutive numbers represented as l[] and r[] where l[i] and r[i] represent the starting and ending marks (inclusive) of the i-th interval. 

The intervals are sorted in increasing order and do not overlap.
The rank of a mark is defined by its position among all valid marks in increasing order, with the smallest mark assigned rank 1, the next smallest rank 2, and so on.
Given an array rank[]. for each value in rank[], find the corresponding mark and return as an array.

Examples:

Input: l[] = [1, 6, 14], r[] = [3, 9, 15], rank[] = [2, 5, 8]
Output: [2, 7, 14]
Explanation: The valid marks are 1, 2, 3, 6, 7, 8, 9, 14, 15. Their corresponding ranks are 1 to 9 as there are 9 distinct marks. Therefore, rank 2 corresponds to mark 2, rank 5 corresponds to mark 7, and rank 8 corresponds to mark 14.
Input: l[] = [5, 10], r[] = [7, 12], rank[] = [1, 4, 6]
Output: [5, 10, 12]
Explanation: The valid marks are 5, 6, 7, 10, 11, 12. Their corresponding ranks are 1 to 6 in increasing order. Hence, rank 1 corresponds to mark 5, rank 4 corresponds to mark 10, and rank 6 corresponds to mark 12.
 

Constraints:

1 ≤ l.size(), l[i], r.size(), r[i], rank.size(), rank[i] ≤ 105
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findInterval(vector<int> &prefix, int low, int high, int rank) {
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (prefix[mid] < rank)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        int n = l.size();
        vector<int> prefix(n);
        prefix[0] = r[0] - l[0] + 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (r[i] - l[i] + 1);
        }
        vector<int> ans(rank.size());
        for (int i = 0; i < rank.size(); i++) {
            int idx = findInterval(prefix, 0, n - 1, rank[i]);
            int diff = prefix[idx] - rank[i];
            ans[i] = r[idx] - diff;
        }
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    int q;
    cin >> q;
    vector<int> rank(q);
    for (int i = 0; i < q; i++)
        cin >> rank[i];
    Solution obj;
    vector<int> ans = obj.getMarks(l, r, rank);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}