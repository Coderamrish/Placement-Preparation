/*
Given a matrix mat[][] of size n x m, where mat[i][j] represents the signal strength of a communication tower. Two control stations monitor the network:

Station P covers the top and left boundaries of the grid.
Station Q covers the bottom and right boundaries of the grid.
A signal can propagate from a tower to one of its neighbouring towers in the four directions (North, South, East, and West) only if the neighbouring tower has a signal strength less than or equal to that of the current tower.

Determine the number of towers (x, y) from which a signal can eventually reach both Station P and Station Q. Any tower located on a boundary covered by a station can transmit directly to that station.

Examples:

Input: mat[][] = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
Output: 7
Explanation: 

(0, 4) & (4, 0) are part of both P & Q 
(1, 3) reaches P using (1,3)->(0,3) and Q using (1,3)->(1,4)
(1, 4) reaches P using (1,4)->(1,3)->(1,2)->(0,2) and it is on Q
(2, 2) reaches P using (2,2)->(2,1)->(2,0) and Q using (2,2)->(2,3)->(2,4)
(3, 0) is on P and reaches Q using (3,0)->(4,0)
(3, 1) reaches P using (3,1)->(3,0) and Q using (3,1)->(4,1)
Input: mat[][] = [[2, 2], [2, 2]]
Output: 4
Explanation: In the following example, all cells allow signals to propagate to both the stations.
Constraints:
1 ≤ n, m ≤ 103
1 ≤ mat[i][j] ≤ 103 
 Reverse BFS from Both Stations - O(n * m) Time and O(n * m) Space
The idea is to perform two reverse BFS traversals starting from the boundary cells of both stations. During traversal, move only to adjacent cells with greater than or equal signal strength, mark the reachable cells for each station, and finally count the cells reachable from both stations.

Let us understand with an example:
Input: mat[][] = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
Start a reverse BFS from the top and left boundaries to mark all cells reachable from Station P.
Similarly, perform another reverse BFS from the bottom and right boundaries to mark all cells reachable from Station Q.
A cell is considered valid only if it is marked as reachable in both traversals.
The common reachable cells are (0,4), (1,3), (1,4), (2,2), (3,0), (3,1), and (4,0).
Hence, the total number of such cells is 7.
*/
#include <iostream>
#include <vector>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &mat,
         vector<vector<bool>> &vis) {
    int n = mat.size();
    int m = mat[0].size();
    vis[row][col] = true;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++) {
        int newRow = row + dr[k];
        int newCol = col + dc[k];
        if (newRow >= 0 && newRow < n &&
            newRow < n && newCol >= 0 && newCol < m &&
            !vis[newRow][newCol] &&
            mat[newRow][newCol] >= mat[row][col]) {
            dfs(newRow, newCol, mat, vis);
        }
    }
}
int countCoordinates(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> stationP(n, vector<bool>(m, false));
    vector<vector<bool>> stationQ(n, vector<bool>(m, false));
    for (int j = 0; j < m; j++)
        dfs(0, j, mat, stationP);
    for (int i = 0; i < n; i++)
        dfs(i, 0, mat, stationP);
    for (int j = 0; j < m; j++)
        dfs(n - 1, j, mat, stationQ);
    for (int i = 0; i < n; i++)
        dfs(i, m - 1, mat, stationQ);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (stationP[i][j] && stationQ[i][j])
                ans++;
        }
    }
    return ans;
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
    cout << countCoordinates(mat);
    return 0;
}