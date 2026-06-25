/*
3.	Given a string, split it into exactly 3 palindromic substrings. If it's not possible, print "Impossible".
Input Format:
•	Single string
Output Format:
•	Three lines: each palindromic substring, or "Impossible"
Sample Input
nayannamantenet
Output
nayan
naman
tenet

Approach - Step 1: Precompute all palindromic substrings using DP
 Step 2: Find two cut points to form 3 palindromes
TC:O(n^2) SC:O(n)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (n < 3) {
        cout << "Impossible";
        return 0;
    }
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len <= 2)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }
    for (int i = 0; i < n - 2; i++) {
        if (!dp[0][i]) continue;
        for (int j = i + 1; j < n - 1; j++) {
            if (dp[i + 1][j] && dp[j + 1][n - 1]) {
                cout << s.substr(0, i + 1) << endl;
                cout << s.substr(i + 1, j - i) << endl;
                cout << s.substr(j + 1) << endl;
                return 0;
            }
        }
    }
    cout << "Impossible";
    return 0;
}