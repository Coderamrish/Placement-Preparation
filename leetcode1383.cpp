/*
You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of its engineers' speeds multiplied by the minimum efficiency among its engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

 

Example 1:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
Example 2:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
Example 3:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
 

Constraints:

1 <= k <= n <= 105
speed.length == n
efficiency.length == n
1 <= speed[i] <= 105
1 <= efficiency[i] <= 108
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
long long maxperformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    const long long MOD = 1e9 + 7;
    vector<pair<int, int>> team;
    team.reserve(n);
    for (int i = 0; i < n; ++i) {
        team.push_back({efficiency[i], speed[i]});
    }
    sort(team.begin(), team.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });
    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long totalSpeed = 0;
    long long maxPerf = 0;
    for (const auto& engineer : team) {
        int eff = engineer.first;
        int spd = engineer.second;
        totalSpeed += spd;
        minHeap.push(spd);
        if ((int)minHeap.size() > k) {
            totalSpeed -= minHeap.top();
            minHeap.pop();
        }
        maxPerf = max(maxPerf, totalSpeed * (long long)eff);
    }
    return maxPerf % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> speed(n);
    vector<int> efficiency(n);
    for (int i = 0; i < n; ++i) {
        cin >> speed[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> efficiency[i];
    }
    cout << maxperformance(n, speed, efficiency, k) << "\n";
    return 0;
}