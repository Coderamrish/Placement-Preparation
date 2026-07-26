/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false
Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
bool validAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
   int cnt[26] = {0};
   for(int i = 0 ; i < s.length(); i++) {
    cnt[s[i] - 'a']++;
    cnt[t[i] - 'a']--;
   }
   for(int i = 0; i < 26; i++) {
    if(cnt[i] != 0) return false;
   }
   return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    cout << (validAnagram(s, t) ? "True" : "False");
    return 0;
}