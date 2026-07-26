/*
Given a string s, find the length of the longest substring without duplicate characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int lengthoflongestSubstring(string s) {
    vector<int>lastIndex(256, -1);
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.length(); right++) {
unsigned char current = s[right];
if(lastIndex[current] >= left) {
    left = lastIndex[current] + 1;
}
lastIndex[current] = right;
maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin , s);
    cout << lengthoflongestSubstring(s) << "\n";
    return 0;
}