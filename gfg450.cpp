/*
Given a string s consisting of lowercase English letters, find the maximum number of characters between any two identical characters. If no character repeats, return -1.

Examples :

Input: s = "socks"
Output: 3
Explanation: There are 3 characters between the two occurrences of 's'.
Input: s = "for"
Output: -1
Explanation: No repeating character present.
Constraints:
1 ≤ |s| ≤ 105
Approach - use  First Occurrence Tracking - O(n) Time O(1) Space
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxCharGap(string &s) {
        int n = s.size();
        vector<int> first(26, -1);
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) {
                first[ch] = i;
            } else {
                ans = max(ans, i - first[ch] - 1);
            }
        }
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    if (cin >> s) {
        Solution solver;
        cout << solver.maxCharGap(s) << "\n";
    } 
    return 0;
}