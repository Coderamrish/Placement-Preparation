/*
Given a binary string s consists only of 0s and 1s. Calculate the number of substrings that have more 1s than 0s.

Examples:

Input: s = "011"
Output: 4
Explanation: There are 4 substring which has more 1s than 0s. i.e "011","1","11" and "1"
Input: s = "0000"
Output: 0
Explanation: There is no substring with more 1s than 0s
Constraints:
1 < |s| <  6 * 104
Approach: - Using Prefix Sum - O(n) Time and O(n) Space
The idea is to treat '1' as +1 and '0' as -1, so a substring with a positive sum has more 1s than 0s. We use prefix balances to avoid checking every substring separately. A frequency array stores how many times each balance occurs, while minus tracks invalid states where zeros are greater than or equal to ones. By updating these values dynamically, we count all valid substrings in linear time.

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int countSubstringsWithMoreOnes(string &s) {
    int n = s.size();
    int ans = 0;
    int zero = n;
    int minus = 0;
    vector<int> mp(2 * n + 1, 0);
    int cur = zero;
    for (auto i : s) {
        if (i == '0') cur--;
        else cur++;
        if (cur <= zero) {
            minus++;
        } 
        mp[cur]++;
    }
    for (int i = 0; i < n; i++) {
        ans += (n - i - minus);
        if (s[i] == '1') {
            mp[zero + 1]--;
            zero++;
            minus += mp[zero];
        } else {
            mp[zero - 1]--;
            zero--;
            minus--;
            minus -= mp[zero + 1];
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    if (cin >> s) {
        int result = countSubstringsWithMoreOnes(s);
        cout << result << "\n";
    }
    return 0;
}