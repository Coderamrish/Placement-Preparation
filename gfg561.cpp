/*
Given a rectangular grid with n rows and m columns, and a string s representing a sequence of movement commands. Geek can start from any cell of the grid and follows all the commands in s in the same order.

The string s consists only of the characters L, R, D, and U, where:

L: Move one cell left, from (i, j) to (i, j - 1).
R: Move one cell right, from (i, j) to (i, j + 1).
D: Move one cell up, from (i, j) to (i - 1, j).
U: Move one cell down, from (i, j) to (i + 1, j).
Determine whether there exists at least one starting cell such that Geek remains within the grid while following all the commands in s.

Examples:

Input: n = 1, m = 1, s = "R"
Output: false
Explanation: There is only one cell(1, 1). So Geek can only start from (1, 1). On taking right(R) Geek moves to (1, 2), which is out of grid. Therefore, there is no cell from where Geek can start and remain inside the grid after tracing the route. 
Input: n = 2, m = 3, s = "LLRU"
Output: true
Explanation: One possible cell is (1, 3). (1, 3) -> (1, 2) -> (1, 1) -> (1, 2) -> (2, 2). Thus, there is a cell from where if Geek starts, it remains inside the grid throughout tracing the route.
frame_3972
Constraints:

1 ≤ n, m, s.size() ≤ 104
s consists only of the characters L R D and U.
*/
#include <bits/stdc++.h>
using namespace std;
bool isPossible(int n, int m, string &s)
{
    int row = 0;
    int col = 0;
    int minRow = 0;
    int maxRow = 0;
    int minCol = 0;
    int maxCol = 0;
    for (char ch : s) {
        if (ch == 'L')
            col--;
        else if (ch == 'R')
            col++;
        else if (ch == 'U')
            row--;
        else if (ch == 'D')
            row++;
        minRow = min(minRow, row);
        maxRow = max(maxRow, row);
        minCol = min(minCol, col);
        maxCol = max(maxCol, col);
    }
    int height = maxRow - minRow + 1;
    int width = maxCol - minCol + 1;
    return height <= n && width <= m;
}
int main()
{
    int n = 2;
    int m = 3;
    string s = "LLRU";
    cout << boolalpha << isPossible(n, m, s) << endl;
    return 0;
}