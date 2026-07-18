/*
You are given a string S.
split the string into the minimum number of contigious substrings such that every substring is a palindrome.
A palindrome is a string that reads the same from the forward and backwards
Return the minimum number of palindromic substrings required to partition the entire string
Note:
Every character of the string must belong to exactly one substring
Consider both odd length and even length palindromes while partitionig
Input format:
A single string S.
output format:
Print the single integer representing the minimum number of palindromic substrings required.
ex1:
input:
abaaccabb
output :
2
EX:
input:
racecar
output:
1
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int minpalindromicsubstring(string &s) {
    int n = s.length();
    if(n == 0) return 0;
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    vector<int>dp(n, 0);
    for(int i = 0; i < n; i++) {
        int min_subs = i + 1;
        for (int j = 0; j <= i; j++) {
            if(s[i] == s[j] && (i - j < 2 || isPal[j + 1][i -1])) {
                isPal[j][i] = true;
                if(j == 0) {
                    min_subs = 1;
                } else {
                    min_subs = min(min_subs, dp[j - 1] + 1 );
                }
            }
        }
        dp[i] = min_subs;
    }
    return dp[n -1];
}
int main() {
    string s;
    cin >> s;
    cout << minpalindromicsubstring(s);
    return 0;
}