/*
Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 

Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:

The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
Example 2:

Input: s = "aaaa"

Output: 2

Explanation:

The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 

Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;
        while (freq[s[right]] > 2) {
            freq[s[left]]--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    cout << ans << endl;
    return 0;
}