/*
Given a positive integer n, consider a 4n * 4n matrix filled with integers from 1 to (4n) * (4n) in row-major order (left to right, top to bottom). Form two coils from the matrix:

The first coil starts from the top-left cell (0, 0) and spirals inward.
The second coil starts from the bottom-right cell (4n - 1, 4n - 1) and spirals inward in the opposite direction.
Return these two coils in the same order.

Examples:

Input: n = 1
Output: [[1, 5, 9, 13, 14, 15, 11, 7], [16, 12, 8, 4, 3, 2, 6, 10]] 
Explanation: The matrix is 
 
So, the two coils are as given in the Output.
Input: n = 2
Output:
[[1, 9, 17, 25, 33, 41, 49, 57, 58, 59, 60, 61, 62, 63, 55, 47, 39, 31, 23, 15, 14, 13, 12, 11, 19, 27, 35, 43, 44, 45, 37, 29], 
 [64, 56, 48, 40, 32, 24, 16, 8, 7, 6, 5, 4, 3, 2, 10, 18, 26, 34, 42, 50, 51, 52, 53, 54, 46, 38, 30, 22, 21, 20, 28, 36]]  
Explanation:
Constraints:
1 ≤ n ≤ 20
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> formCoils(int n) {
    int m = 8 * n * n;
    vector<int> coil1(m), coil2(m);
    coil1[0] = 8 * n * n + 2 * n;
    int curr = coil1[0];
    int flag = 1, step = 2;
    int index = 1;
    while (index < m) {
        for (int i = 0; i < step && index < m; i++)
            curr = coil1[index++] = curr - 4 * n * flag;
        for (int i = 0; i < step && index < m; i++)
            curr = coil1[index++] = curr + flag;
        flag *= -1;
        step += 2;
    }
    for (int i = 0; i < m; i++)
        coil2[i] = 16 * n * n + 1 - coil1[i];
    reverse(coil1.begin(), coil1.end());
    reverse(coil2.begin(), coil2.end());
    return {coil2, coil1};
}
int main() {
    int n = 1;
    vector<vector<int>> ans = formCoils(n);
    cout << "[";
    for (int i = 0; i < 2; i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
            if (j + 1 < ans[i].size())
                cout << ", ";
        }
        cout << "]";
        if (i == 0)
            cout << ", ";
    }
    cout << "]";
    return 0;
}