/*
Given a binary matrix mat[][] of size n*m and an integer k, process a list of queries queries[][]. Each query contains coordinates [i, j] of the center of a square.

For every query, find the side length of the largest odd-sized square centered at cell (i, j) such that the square contains at most k ones.
 A square centered at (i, j) expands outward symmetrically in all four directions by the same number of cells, so its side length is always odd.
Examples:

Input: mat[][] = [[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1, 0]], queries[][] = [[1, 2]], k = 9
Output: [3]
Explanation: The largest odd-sized square centered at (1, 2) is the 3 × 3 square spanning rows 0 to 2 and columns 1 to 3. 
It contains 6 ones, which is at most k = 9. Hence, the answer is 3.
Input: mat[][] = [[1, 1, 1], [1, 1, 1], [1, 1, 1]], queries[][] = [[1, 1], [2, 2]], K = 9
Output: [3, 1]
Explanation: For query (1, 1), the largest valid square is the entire 3 × 3 matrix, which contains 9 ones. Hence, the answer is 3.
For query (2, 2), no expansion is possible without going outside the matrix, so only the 1 × 1 square centered at (2, 2) is valid. Hence, the answer is 1.
Constraints:
1 ≤ mat.size(), mat[0].size() ≤ 500
1 ≤ queries.size() ≤ 104
0 ≤ queries[q][0] < mat.size()
0 ≤ queries[q][1] < mat[0].size()
0 ≤ k ≤ mat.size() * mat[0].size()
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> largestSquare(vector<vector<int>>& mat,
                          vector<vector<int>>& queries,
                          int k) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefix[i + 1][j + 1] =
                prefix[i][j + 1]
                + prefix[i + 1][j]
                - prefix[i][j]
                + mat[i][j];
        }
    }
    vector<int> res;
    for (auto &q : queries) {
        int i = q[0];
        int j = q[1];
        int minDist = min({i, j, n - i - 1, m - j - 1});
        if (mat[i][j] > k) {
            res.push_back(-1);
            continue;
        }
        int lo = 0;
        int hi = minDist;
        int best = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int r1 = i - mid;
            int c1 = j - mid;
            int r2 = i + mid;
            int c2 = j + mid;
            int sum =
                prefix[r2 + 1][c2 + 1]
                - prefix[r1][c2 + 1]
                - prefix[r2 + 1][c1]
                + prefix[r1][c1];
            if (sum <= k) {
                best = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        res.push_back(2 * best + 1);
    }
    return res;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    int k;
    cin >> k;
    vector<int> ans = largestSquare(mat, queries, k);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}