/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
Constraints:
1 <= k <= points.length <= 104
-104 <= xi, yi <= 104
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> kClosestPoints(vector<vector<int>>& points, int k) {
    priority_queue<pair<long long, vector<int>>> pq;
    for (auto &point : points) {
        long long dist = 1LL * point[0] * point[0] +
                         1LL * point[1] * point[1];
        pq.push({dist, point});
        if (pq.size() > k)
            pq.pop();
    }
    vector<vector<int>> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }
    int k;
    cin >> k;
    vector<vector<int>> ans = kClosestPoints(points, k);
    for (auto &point : ans) {
        cout << point[0] << " " << point[1] << "\n";
    }
    return 0;
}
// TC: O(log k)
// SC:O(K) 