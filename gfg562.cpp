/*
Given a string s, return the sum of the beauty of all substrings of s. The beauty of a substring is defined as the difference between the maximum and minimum frequencies of the characters present in that substring.

Examples:

Input: s = "aaac"
Output: 3
Explanation: The substrings with non-zero beauty are "aaac" and "aac". 
For "aaac", the frequencies are a = 3 and c = 1. Its beauty is 3 − 1 = 2. 
For "aac", the frequencies are a = 2 and c = 1. Its beauty is 2 − 1 = 1. 
The remaining substrings have a beauty of 0. Therefore, the sum of the beauties of all substrings is 2 + 1 = 3.
Input: s = "aabc"
Output: 2
Explanation: The substrings with non-zero beauty are "aab" and "aabc". 
For "aab", the frequencies are a = 2 and b = 1. Its beauty is 2 − 1 = 1. 
For "aabc", the frequencies are a = 2, b = 1, and c = 1. Its beauty is 2 − 1 = 1. 
Therefore, the sum of the beauties of all substrings is 1 + 1 = 2.
Constraints:

1 ≤ s.size() ≤ 500
s consists only of lowercase English alphabets
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;
int beautySum(string &s)
{
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        int cnt[26] = {0};
        for (int j = i; j < (int)s.size(); ++j)
        {
            cnt[s[j] - 'a']++;
            int mx = 0;
            int mn = INT_MAX;
            for (int k = 0; k < 26; ++k)
            {
                if (cnt[k] > 0)
                {
                    mx = max(mx, cnt[k]);
                    mn = min(mn, cnt[k]);
                }
            }
            ans += mx - mn;
        }
    }
    return ans;
}
int main()
{
    string s = "aaac";
    int res = beautySum(s);
    cout << res << '\n';
    return 0;
}