/*
Given a string str, Find the number of distinct subsequences that can be formed from it.
A subsequence is a sequence derived from the original string by deleting zero or more characters without changing the relative order of the remaining characters.
Note: Answer can be very large, so, ouput will be answer modulo 109+7.
Examples: 
Input: str = "gfg"
Output: 7
Explanation: The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" 

Test Case	Input String	Expected Output
1                              gfg                                  7
2                              ggg                                 4
3                              g                                      2
4                              gg                                    3
5                              gf                                     4
Appraoch - If all characters in a string of length $n$ are unique, the total number of subsequences is $2^n$ (since every character has 2 choices: either be included or excluded).However, when characters repeat, duplicate subsequences are created. To avoid counting them multiple times:Let $dp[i]$ represent the number of distinct subsequences formed by the prefix of the string up to index $i$.Base case: $dp[0] = 1$ (representing the empty string "").For each character str[i-1]:If it's a new character: It doubles the number of existing subsequences.$$dp[i] = 2 \times dp[i-1]$$If it has appeared before: It will recreate some subsequences that were already counted when that character last appeared. To remove duplicates, subtract the count of subsequences before its previous occurrence.$$dp[i] = (2 \times dp[i-1]) - dp[\text{last\_occurrence}[str[i-1]] - 1]$$
TC:O(n) SC:O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int distinctSubsequence(string & str) {
    int n = str.length();
    int MOD = 1e9 + 7;
    vector<long long>dp(n + 1, 0);
    dp[0] = 1;
    vector<int>last(256, -1);
    for(int i = 1; i <= str.length(); i++) {
        char ch = str[i - 1];
        dp[i] = (2*dp[i-1]) % MOD;
        if(last[ch] != -1) {
            int prev_idx = last[ch];
            dp[i] = (dp[i] - dp[prev_idx - 1] + MOD) % MOD;
        }
        last[ch] = i;
    }
    return dp[n];
}
int main() {
    string str;
    if(cin >> str) {
        cout << distinctSubsequence(str);
    }
    return 0;
}