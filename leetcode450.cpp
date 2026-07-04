/*
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
 

Example 1:


Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.
Example 2:


Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
 

Constraints:

2 <= n <= 105
1 <= roads.length <= 105
roads[i].length == 3
1 <= ai, bi <= n
ai != bi
1 <= distancei <= 104
There are no repeated edges.
There is at least one path between 1 and n.
Approach - using bfs TC:O(V + E) SC:O(V + E)
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int countSubstringsWithMoreOnes(string &s) {
    int n = s.size();
    int ans = 0;
    int zero = n;
    int minus = 0;
    vector<int> mp(2 * n + 1, 0);
    int cur = zero;
    for (auto i : s) {
        if (i == '0') cur--;
        else cur++;    
        if (cur <= zero) {
            minus++;
        } 
        mp[cur]++;
    } 
    for (int i = 0; i < n; i++) {
        ans += (n - i - minus);
        if (s[i] == '1') {
            mp[zero + 1]--;
            zero++;
            minus += mp[zero];
        } else {
            mp[zero - 1]--;
            zero--;
            minus--;
            minus -= mp[zero + 1];
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    if (cin >> s) {
        int result = countSubstringsWithMoreOnes(s);
        cout << result << "\n";
    }  
    return 0;
}