/*
You are given a palindromic string s.
Return the lexicographically smallest palindromic permutation of s.
Example 1:
Input: s = "z"
Output: "z"
Explanation:
A string of only one character is already the lexicographically smallest palindrome.
Example 2:
Input: s = "babab"
Output: "abbba"
Explanation:
Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
Example 3:
Input: s = "daccad"
Output: "acddca"
Explanation:
Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
Constraints:
1 <= s.length <= 105
s consists of lowercase English letters.
s is guaranteed to be palindromic.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
string smallestPalindrome(string s) {
int cnt[26] = {0};
for(char c: s) {
    cnt[c - 'a']++;
}
string left = "";
char mid = '\0';
for(int i = 0; i < 26; i++) {
    left.append(cnt[i] / 2, char('a' + i));
    if(cnt[i] % 2 == 1) {
        mid = char('a' + i);
    }
}
string right  = left;
reverse(right.begin(), right.end());
if(mid != '\0')
return left + mid + right;
return left + right;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
  getline(cin, s);
  stringstream ss(s);
cout << smallestPalindrome(s);
return 0;
}