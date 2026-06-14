/*
Given a matrix mat[][] of size n × m consisting of 0s and 1s. You start at the top-left cell (0, 0) and initially move in the left-to-right direction (i.e., towards the right).

While traversing the matrix, follow these rules:

If the current cell contains 0, continue moving in the same direction.
If the current cell contains 1, change your direction to the right (clockwise turn), and update the cell value to 0.
You continue this process until you move outside the boundaries of the matrix. Your task is to determine the coordinates (row and column index) of the cell from which you exit the matrix.

Examples:

Input: mat[][] = [[0, 1, 0],
               [0, 1, 1], 
               [0, 0, 0]]
Output: [1, 0]
Explanation: 

From the image we can see that, enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed. Hence, exit point reached at [1, 0].
Input: mat[][] = [[0, 0]]
Output: [0, 1]
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell [0, 1].
Constraints:
1 ≤ n, m ≤ 100
Approach - using simulation direction Traversal 
TC:O(n * m) SC:O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int>exitPoint(vector<vector<int>>& mat) {
    int i = 0, j = 0;
    int dir = 0;
    while(true) {
        dir = (dir + mat[i][j]) % 4;
if(mat[i][j] == 1) {
    mat[i][j] = 0;
}
if(dir == 0) {
    j++;
} else if(dir == 1) {
    i++;
} else if(dir == 2) {
    j--;
} else if(dir == 3) {
    i--;
}if(i < 0) {
    i++;
    break;
} else if(i == mat.size()) {
    i--;
    break;
} else if(j < 0) {
    j++;
    break;
} else if(j == mat[0].size()) {
    j--;
    break;
}
    }
    vector<int>v(i, j);
    return v;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    vector<int> ans = exitPoint(mat);
    cout << ans[0] << " " << ans[1];
    return 0;
}