/*
Given a string s of length n containing only lowercase English letters, and a permutation array p[] of length n containing integers from 0 to n - 1.

On the (i + 1)th day, the character at index p[i] in the string is replaced with '?'. For example:

On day 1, replace s[p[0]] with '?'.
On day 2, replace s[p[1]] with '?'.
On day 3, replace s[p[2]] with '?'.
And so on.
Find the minimum number of days required so that no two adjacent characters in s are equal, unless at least one of them is '?'.

Formally, for every index i (0 <= i < n - 1), the string must satisfy: If s[i] != '?' and s[i+1] != '?', then s[i] != s[i+1].

Examples:

Input: s = "aabb", p = [2, 1, 3, 0]
Output: 2
Explanation:
On Day 1, we replace s[p[0]] (index 2) with '?'. String becomes "aa?b". Index 0 and 1 still have equal adjacent characters 'a'.
On Day 2, we replace s[p[1]] (index 1) with '?'. String becomes "a??b". Now no two adjacent non-'?' characters are equal.
Input: s = "abca", p = [3, 0, 2, 1]
Output: 0
Explanation:
The initial string "abca" already satisfies the condition without replacing any characters.
Constraints:

1 ≤ s.size() ≤ 105
0 ≤ p[i] < s.size()
s consists only of lowercase English alphabets
p.size() = s.size()

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int getMinimumDays(string &s, vector<int> &p)
{
    int n = s.size();
    int t = 0, i;
    for (i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            t++;
    }
    if (t == 0)
        return 0;
    for (i = 0; i < n; i++)
    {
        int in = p[i];
        if (in - 1 >= 0 && s[in - 1] == s[in])
            t--;
        if (in + 1 < n && s[in] == s[in + 1])
            t--;
        s[in] = '?';
        if (t == 0)
            return i + 1;
    }
    return n;
}
int main()
{
    string s = "aabb";
    vector<int> p = {2, 1, 3, 0};
    cout << getMinimumDays(s, p) << endl;
    return 0;
}