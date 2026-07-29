/*
You are given a palindromic string s and an integer k.
Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
Example 1:
Input: s = "abba", k = 2
Output: "baab"
Explanation:
The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
Example 2:
Input: s = "aa", k = 2
Output: ""
Explanation:
There is only one palindromic rearrangement: "aa".
The output is an empty string since k = 2 exceeds the number of possible rearrangements.
Example 3:
Input: s = "bacab", k = 1
Output: "abcba"
Explanation:
The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
Constraints:
1 <= s.length <= 104
s consists of lowercase English letters.
s is guaranteed to be palindromic.
1 <= k <= 106
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
static const long long MAX_K = 1e6 + 1;
long long nCk(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    long long res = 1;
    for (long long i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
        if (res >= MAX_K) return MAX_K;
    }
    return res;
}
long long countArrangements(const vector<int>& freq) {
    long long total = 0;
    for (int f : freq) total += f;
    long long res = 1;
    for (int f : freq) {
        if (f > 0) {
            res *= nCk(total, f);
            if (res >= MAX_K) return MAX_K;
            total -= f;
        }
    }
    return res;
}
string getSmallestPalindrome(string s, int k) {
    vector<int> charCount(26, 0);
    for (char c : s) {
        charCount[c - 'a']++;
    }
    vector<int> halfCount(26, 0);
    string midLetter = "";
    for (int i = 0; i < 26; ++i) {
        halfCount[i] = charCount[i] / 2;
        if (charCount[i] % 2 != 0) {
            midLetter = string(1, (char)('a' + i));
        }
    }
    long long totalPerms = countArrangements(halfCount);
    if (k > totalPerms) {
        return "";
    }
    int halfLen = 0;
    for (int count : halfCount) halfLen += count;
    string leftHalf = "";
    for (int step = 0; step < halfLen; ++step) {
        for (int i = 0; i < 26; ++i) {
            if (halfCount[i] == 0) continue;
            halfCount[i]--;
            long long arrangements = countArrangements(halfCount);
            if (arrangements >= k) {
                leftHalf += (char)('a' + i);
                break;
            } else {
                k -= arrangements;
                halfCount[i]++; 
            }
        }
    }
    string rightHalf = leftHalf;
    reverse(rightHalf.begin(), rightHalf.end());
    return leftHalf + midLetter + rightHalf;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    if (cin >> s >> k) {
        cout << getSmallestPalindrome(s, k) << "\n";
    }
    return 0;
}