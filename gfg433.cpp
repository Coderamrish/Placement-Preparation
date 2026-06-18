/*
Given a binary matrix mat[][] containing only 0s and 1s, find the total coverage of all 0's. The coverage of a particular 0 cell is defined by checking 1's in its four directions (left, right, up, and down). For each direction, if there is at least one 1 anywhere between the 0 and the boundary of the matrix, the coverage increases by one.

Return the sum of the coverage values for all 0 cells in the matrix.

Examples:

Input : mat[][] = [[1, 1, 1, 0],
                  [1, 0, 0, 1]]
Output : 8
Explanation: Coverage of first zero is 2. Coverages of other two zeros is 3 Total coverage = 2 + 3 + 3 = 8
2056958046
Input: mat[][] = [[0, 1, 0],
               [0, 1, 1],
               [0, 0, 0]]
Output: 6
Explanation: Total Coverage is 1 + 2 + 1 + 0 + 1 + 1 = 6   

Input: mat[][] = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage. Therefore answer for this test case is 1.
Constraints:
1 ≤ matrix.size, matrix[0].size ≤ 100

approach 1 - using the four direction traversal TC:O(r * c) SC:O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findCoverage(vector<vector<int>>& mat)
{
    int r = mat.size();
    int c = mat[0].size();
    int res = 0;
    for (int i = 0; i < r; i++)
    {
        bool isOne = false;
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 1)
                isOne = true;
            else if (isOne)
                res++;
        }
        isOne = false;
        for (int j = c - 1; j >= 0; j--)
        {
            if (mat[i][j] == 1)
                isOne = true;
            else if (isOne)
                res++;
        }
    }
    for (int j = 0; j < c; j++)
    {
        bool isOne = false;
        for (int i = 0; i < r; i++)
        {
            if (mat[i][j] == 1)
                isOne = true;
            else if (isOne)
                res++;
        }
        isOne = false;
        for (int i = r - 1; i >= 0; i--)
        {
            if (mat[i][j] == 1)
                isOne = true;

            else if (isOne)
                res++;
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> mat = {
        {0, 0, 0, 0},
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 0, 0}
    };
    cout << findCoverage(mat);
    return 0;
}