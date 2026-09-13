/*
You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.

 

Example 1:


Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.

The number of positions that have a 1 in both images is 3 (shown in red).

Example 2:

Input: img1 = [[1]], img2 = [[1]]
Output: 1
Example 3:
Input: img1 = [[0]], img2 = [[0]]
Output: 0
Constraints:
n == img1.length == img1[i].length
n == img2.length == img2[i].length
1 <= n <= 30
img1[i][j] is either 0 or 1.
img2[i][j] is either 0 or 1.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    ones1.push_back({i, j});
                }
                if (img2[i][j] == 1) {
                    ones2.push_back({i, j});
                }
            }
        }
        map<pair<int, int>, int> mp;
        int answer = 0;
        for (auto [x1, y1] : ones1) {
            for (auto [x2, y2] : ones2) {
                int dx = x2 - x1;
                int dy = y2 - y1;
                mp[{dx, dy}]++;
                answer = max(answer, mp[{dx, dy}]);
            }
        }
        return answer;
    }
};
int main() {
    Solution obj;
    vector<vector<int>> img1 = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    vector<vector<int>> img2 = {
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1}
    };
    cout << obj.largestOverlap(img1, img2) << endl;
    return 0;
}