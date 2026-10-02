/*
Given a string s, find the lexicographically smallest string after rotating the string left any number of times including 0.

Example:

Input: s = "abcd"
Output: "abcd"
Explanation: String after each rotation are "abcd", "bcda", "cdab", "dabc" and so on. Lexicographically smallest among them is "abcd".
Input: s = "baca"
Output: "abac"
Explanation: Strings after each rotation are "baca", "acab", "caba", "abac" and so on. Lexicographically smallest among them is "abac".
Constraints:

1 ≤ s.size() ≤ 106
s consists only of lowercase English alphabets
*/
#include <bits/stdc++.h>
using namespace std;
string lexiString(string &s) {
    string doubled = s + s;
    int n = doubled.size();
    vector<int> f(n, -1);
    int k = 0;
    for (int j = 1; j < n; j++) {
        char sj = doubled[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != doubled[k + i + 1]) {
            if (sj < doubled[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if (sj != doubled[k + i + 1]) {
            if (sj < doubled[k]) {
                k = j;
            }
            f[j - k] = -1;
        }
        else {
            f[j - k] = i + 1;
        }
    }
    return doubled.substr(k, s.size());
}
int main() {
    string s = "baca";
    cout << lexiString(s) << endl;
    return 0;
}