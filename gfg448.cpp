/*
Given two strings s1 and s2 consisting of lowercase English letters of length n1 and n2 respectively, find the number of ways to insert exactly one character into string s1 such that the length of the Longest Common Subsequence (LCS) of both strings increases by exactly 1.

Examples :

Input: s1 = "abab", s2 = "abc"
Output: 3
Explanation: The LCS length of the given two strings is 2. There are 3 valid insertions in s1 which increase the LCS length to 3:
"abcab" -> LCS = 3
"abacb" -> LCS = 3
"ababc" -> LCS = 3
Input: s1 = "abcabc", s2 = "abcd"
Output: 4
Explanation: The LCS length of the given two strings is 3. There are 4 valid insertions in s1 which increase the LCS length to 4:
"abcdabc" -> LCS = 4
"abcadcb" -> LCS = 4
"abcabdc" -> LCS = 4
"abcabcd" -> LCS = 4
Constraints:
1<= n1, n2 <=100
Approach -  Prefix and Suffix DP - O(n1 × n2) Time and O(n1 × n2) Space
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> position(26);
    for (int i = 1; i <= n2; i++) {
        position[s2[i - 1] - 'a'].push_back(i);
    }
    vector<vector<int>> lcsl(n1 + 2, vector<int>(n2 + 2, 0));
    vector<vector<int>> lcsr(n1 + 2, vector<int>(n2 + 2, 0));
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1])
                lcsl[i][j] = 1 + lcsl[i - 1][j - 1];
            else
                lcsl[i][j] = max(lcsl[i - 1][j], lcsl[i][j - 1]);
        }
    }
    for (int i = n1; i >= 1; i--) {
        for (int j = n2; j >= 1; j--) {
            if (s1[i - 1] == s2[j - 1])
                lcsr[i][j] = 1 + lcsr[i + 1][j + 1];
            else
                lcsr[i][j] = max(lcsr[i + 1][j], lcsr[i][j + 1]);
        }
    }
    int baseLCS = lcsl[n1][n2];
    int ways = 0;
    for (int i = 0; i <= n1; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            for (int pos : position[c - 'a']) {
                if (lcsl[i][pos - 1] + lcsr[i + 1][pos + 1] == baseLCS) {
                    ways++;
                    break; 
                }
            }
        }
    }
    cout << ways << endl;
    return 0;
}