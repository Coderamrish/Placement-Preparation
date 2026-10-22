/*
Given a string s consisting of lowercase English letters and the character '?', 

Replace every '?' with a lowercase English letter such that the resulting string is a palindrome.
If it is possible to form a palindrome, return the minimum possible sum of the absolute ASCII differences between every pair of adjacent characters in the resulting string.
If it is not possible to form a palindrome, return -1.
Examples:

Input: s = a???c??c????
Output: 4
Explanation: One optimal palindrome is "abbbccccbbba". The sum of the absolute ASCII differences between adjacent characters is 1 + 0 + 0 + 1 + 0 + 0 + 0 + 1 + 0 + 0 + 1 = 4, which is the minimum possible. 
Input: s = a???c??c???c
Output: -1
Explanation: It is not possible to replace the '?' characters to make the string a palindrome because the first and last characters are different and cannot be changed.
Constraints:

1 ≤ s.size() ≤ 105
*/
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
bool isPossible(string &s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != '?' && s[n - i - 1] != '?' && s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
int minimumSum(string &s)
{
    if (!isPossible(s))
        return -1;
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '?' && s[n - i - 1] != '?')
            s[i] = s[n - i - 1];
        else if (s[i] != '?' && s[n - i - 1] == '?')
            s[n - i - 1] = s[i];
    }
    vector<char> st;
    for (int i = 0; i < n;)
    {
        if (s[i] != '?')
        {
            st.push_back(s[i]);
            i++;
        }
        else
        {
            if (!st.empty())
            {
                while (i < n && s[i] == '?')
                    s[i++] = st.back();
                st.pop_back();
            }
            else
            {
                i++;
            }
        }
    }
    st.clear();
    for (int i = n - 1; i >= 0;)
    {
        if (s[i] != '?')
        {
            st.push_back(s[i]);
            i--;
        }
        else
        {
            if (!st.empty())
            {
                while (i >= 0 && s[i] == '?')
                    s[i--] = st.back();
                st.pop_back();
            }
            else
            {
                i--;
            }
        }
    }
    for (char &ch : s)
    {
        if (ch == '?')
            ch = 'a';
    }
    int res = 0;
    for (int i = 0; i + 1 < n; i++)
        res += abs((s[i] - 'a') - (s[i + 1] - 'a'));
    return res;
}
int main()
{
    string s = "a???c??c????";
    cout << minimumSum(s) << endl;
    return 0;
}