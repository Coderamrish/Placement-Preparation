/*
Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.
Example 2:

Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
Output: 2
Explanation:
- "a" appears as a substring in "aaaaabbbbb".
- "b" appears as a substring in "aaaaabbbbb".
- "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.
Example 3:

Input: patterns = ["a","a","a"], word = "ab"
Output: 3
Explanation: Each of the patterns appears as a substring in word "ab".
 

Constraints:

1 <= patterns.length <= 100
1 <= patterns[i].length <= 100
1 <= word.length <= 100
patterns[i] and word consist of lowercase English letters.
Approach - Loop through each string in patterns
Use word.find(pattern) to check if it exists
Count how many patterns are found
TC:O(n*m) SC:O(1)
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<iostream>
#include<climits>
#include<sstream>
#include<vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string>patterns(N);
for(int i = 0; i < N; i++) {
cin >> patterns[i];
}
string word;
cin >> word;
int cnt = 0;
for(const string& p : patterns) {
    if(word.find(p) != string::npos) {
        cnt++;
    }
}
cout << cnt;
return 0;
}