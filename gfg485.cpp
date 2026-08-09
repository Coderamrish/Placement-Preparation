/*
Given a square matrix mat[][] of size n × n. A zigzag sequence starts from the top and ends at the bottom. Two consecutive elements of sequence cannot belong to the same column.
Return the maximum sum of such a zigzag sequence.
Examples:
Input: mat[][] = [[3, 1, 2], [4, 8, 5], [6, 9, 7]]
Output: 18
Explanation:
One optimal zigzag sequence is: 3 -> 8 -> 7, where the sum = 3 + 8 + 7 = 18.
Input: mat[][] = [[1, 2, 4], [3, 9, 6], [11, 3, 15]]
Output: 28
Explanation:
One optimal zigzag sequence is: 4 -> 9 -> 15, where the sum = 4 + 9 + 15 = 28.
Constraints:
1 ≤ n ≤ 100
1 ≤ mat[i][j] ≤ 1000 
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int zigzagSequence(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<int> prev = mat[0];
    for (int i = 1; i < n; i++) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int maxCol = -1;
        for (int j = 0; j < n; j++) {
            if (prev[j] > max1) {
                max2 = max1;
                max1 = prev[j];
                maxCol = j;
            }
            else if (prev[j] > max2) {
                max2 = prev[j];
            }
        }
        vector<int> curr(n);
        for (int j = 0; j < n; j++) {
            if (j == maxCol) {
                curr[j] = mat[i][j] + max2;
            }
            else {
                curr[j] = mat[i][j] + max1;
            }
        }
        prev = curr;
    }
    int ans = INT_MIN;
    for (int j = 0; j < n; j++) {
        ans = max(ans, prev[j]);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    int result = zigzagSequence(mat);
    cout << result << endl;
    return 0;
}