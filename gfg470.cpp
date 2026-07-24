/*
Given a n × n grid mat[][] of integers where values can be negative, find the maximum sum among all possible k × k sub-grids.

Examples:

Input: k = 3, mat[][] = [[1, 2, -1, 4], [-8, -3, 4, 2], [3, 8, 10, -8], [-4, -1, 1, 7]]
Output: 20
Explanation: The 3 × 3 sub-grid [[-3, 4, 2], [8, 10, -8], [-1, 1, 7]] highlighted in red has the maximum sum of 20. 








Input: k = 1, mat[][] = [[4]]
Output: 4
Explanation: Only one 1×1 sub-grid exists with sum 4.

Constraints:

1 ≤ n ≤ 1000
1 ≤ k ≤ n
-1000 ≤ mat[i][j] ≤ 1000
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int maximumSum(vector<vector<int>> & mat, int k) {
    int n = mat.size();
vector<int>colsum(n ,0);
int ans = INT_MIN;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        colsum[j] += mat[i][j];
        if(i >= k) 
        colsum[j] -= mat[i - k][j];
    }
    if(i >= k - 1) 
    {
        int winsum = 0;
        for(int j = 0; j < n; j++) {
            winsum += colsum[j];
            if(j >= k) 
            winsum -= colsum[j - k];
            if(j >= k - 1)
            ans = max(ans, winsum);
        }
    }
}
return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if(!(cin >> n >> k));
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    cout << maximumSum(mat, k);
    return 0;
}