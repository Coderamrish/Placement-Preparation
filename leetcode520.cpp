/*
You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.

Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.

Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.

 

Example 1:

Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]

Output: [2,3]

Explanation:

You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.

Example 2:

Input: intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]

Output: [1,3,5,6]

Explanation:

You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5.

 

Constraints:

1 <= intevals.length <= 5 * 104
intervals[i].length == 3
intervals[i] = [li, ri, weighti]
1 <= li <= ri <= 109
1 <= weighti <= 109
*/
#include <bits/stdc++.h>
using namespace std;
struct T {
    long long weight;
    vector<int> selected;
    T(long long w = 0, vector<int> s = {})
        : weight(w), selected(s) {}
};
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& input) {
        vector<Interval> intervals;
        for (int i = 0; i < (int)input.size(); ++i) {
            intervals.emplace_back(
                input[i][0],
                input[i][1],
                input[i][2],
                i
            );
        }
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<T>> memo(
            n,
            vector<T>(5, T(-1, {}))
        );
        return dp(intervals, memo, 0, 4).selected;
    }
private:
    using Interval = tuple<int, int, int, int>;
    T dp(const vector<Interval>& intervals,
          vector<vector<T>>& memo,
          int i,
          int quota) {
        if (i == (int)intervals.size() || quota == 0) {
            return T();
        }
        if (memo[i][quota].weight != -1) {
            return memo[i][quota];
        }
        T skip = dp(
            intervals,
            memo,
            i + 1,
            quota
        );
        auto [left, right, weight, originalIndex] =
            intervals[i];
        int j = findFirstGreater(
            intervals,
            i + 1,
            right
        );
        T nextRes = dp(
            intervals,
            memo,
            j,
            quota - 1
        );
        vector<int> newSelected = nextRes.selected;
        newSelected.push_back(originalIndex);
        sort(newSelected.begin(), newSelected.end());
        T pick(
            (long long)weight + nextRes.weight,
            newSelected
        );
        if (pick.weight > skip.weight ||
            (pick.weight == skip.weight &&
             pick.selected < skip.selected)) {
            return memo[i][quota] = pick;
        }
        return memo[i][quota] = skip;
    }
    int findFirstGreater(
        const vector<Interval>& intervals,
        int startFrom,
        int rightBoundary) {
        int left = startFrom;
        int right = intervals.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (get<0>(intervals[mid]) > rightBoundary) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> input = {
        {1, 3, 4},
        {2, 4, 5},
        {3, 5, 1},
        {6, 7, 4},
        {5, 8, 3}
    };
    vector<int> answer = solution.maximumWeight(input);
    cout << "Selected indices: ";
    for (int index : answer) {
        cout << index << " ";
    }
    cout << '\n';
    return 0;
}