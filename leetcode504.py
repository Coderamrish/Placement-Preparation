"""
You are given two strings s and target, both having length n, consisting of lowercase English letters.

Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

 

Example 1:

Input: s = "abc", target = "bba"

Output: "bca"

Explanation:

The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
The lexicographically smallest permutation that is strictly greater than target is "bca".
Example 2:

Input: s = "leet", target = "code"

Output: "eelt"

Explanation:

The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
The lexicographically smallest permutation that is strictly greater than target is "eelt".
Example 3:

Input: s = "baba", target = "bbaa"

Output: ""

Explanation:

The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
None of them is lexicographically strictly greater than target. Therefore, the answer is "".
 

Constraints:

1 <= s.length == target.length <= 300
s and target consist of only lowercase English letters.
"""
class Solution:
    def lexGreaterPermutation(self, s, target):
        n = len(s)
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        res = [' '] * n
        def dfs(index, is_greater):
            if index == n:
                return is_greater
            if is_greater:
                start_char_code = 0
            else:
                start_char_code = ord(target[index]) - ord('a')
            for i in range(start_char_code, 26):
                if count[i] > 0:
                    res[index] = chr(ord('a') + i)
                    count[i] -= 1
                    next_is_greater = (
                        is_greater or
                        i > ord(target[index]) - ord('a')
                    )
                    if dfs(index + 1, next_is_greater):
                        return True
                    count[i] += 1
            return False
        if dfs(0, False):
            return ''.join(res)
        else:
            return ""

s = input().strip()
target = input().strip()
obj = Solution()
print(obj.lexGreaterPermutation(s, target))