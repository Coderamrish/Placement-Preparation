"""
Given a binary matrix mat[][] of size n × m containing only 0s and 1s, any pair of columns may be swapped any number of times. Return the maximum area of a rectangle consisting entirely of 1's that can be formed after performing the column swaps.

Examples:

Input: mat[][] = [[0, 1, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 1, 0]]
Output: 6
Explanation: After swapping the 2nd and 3rd columns, the largest rectangle of 1s has an area of 6.
 
Input: mat[][] = [[0, 1, 1, 0, 0], [1, 1, 1, 0, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 1]]
Output: 12
Explanation: After swapping the 4th and 5th columns, the largest rectangle of 1s has an area of 12.

Constraints:

1 ≤ n, m ≤ 103
0 ≤ mat[i][j] ≤ 1
mat.rows = n
mat.cols = m
"""
class Solution:
    def maxArea(self, mat):
        n = len(mat)
        m = len(mat[0])
        height = [[0] * m for _ in range(n)]
        for j in range(m):
            height[0][j] = mat[0][j]
            for i in range(1, n):
                if mat[i][j] == 1:
                    height[i][j] = height[i - 1][j] + 1
        ans = 0
        for i in range(n):
            count = [0] * (n + 1)
            for j in range(m):
                count[height[i][j]] += 1
            col = 0
            for h in range(n, -1, -1):
                while count[h] > 0:
                    height[i][col] = h
                    col += 1
                    count[h] -= 1
            for j in range(m):
                ans = max(ans, height[i][j] * (j + 1))
        return ans
n, m = map(int, input().split())
mat = []
for _ in range(n):
    row = list(map(int, input().split()))
    mat.append(row)
obj = Solution()
print(obj.maxArea(mat))