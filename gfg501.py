""""
Given an array arr[] containing integers from 1 to n exactly once, sort the array in ascending order.

In one operation, you can pick any element and move it either to the beginning or to the end of the array.

Return the minimum number of operations required to sort the array.

Examples:

Input: arr[] = [2, 1, 3]
Output: 1
Explanation: Move 1 to the beginning.
Input: arr[] = [4, 3, 1, 2]
Output: 2
Explanation: Move 3 to the end to get [4, 1, 2, 3]. Then move 4 to the end to get [1, 2, 3, 4].
Constraints:

arr.size() ≤ 105
1 ≤ arr[i] ≤ arr.size()
"""
class Solution:
    def minMoves(self, arr):
        n = len(arr)
        count = [0] * (n + 1)
        for x in arr:
            if count[x - 1] != 0:
                count[x] = count[x - 1] + 1
            else:
                count[x] = 1
        longest = 0
        for i in range(n + 1):
            longest = max(longest, count[i])
        return n - longest
n = int(input())
arr = list(map(int, input().split()))
obj = Solution()
print(obj.minMoves(arr))