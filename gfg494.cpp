/*
Geek wants to send a secret message to his friend Keeg. Instead of sending the original message directly, he encrypts it by inserting the character '*'.

Keeg decodes the message as follows:

Traverse the encoded string from left to right and initialize the original string as empty.
Whenever a normal character appears, append it to the current original string.
Whenever '*' is encountered, remove it and append all characters before it to the end of the current original string.
Repeat until no '*' remains.

Given the original string s, find the lexicographically smallest encrypted string that decodes to s.

Examples :

Input: s = "ababcababcd"
Output: ab*c*d
Explanation: We can encrypt the string in following way : "ababcababcd" -> "ababc*d" -> "ab*c*d"
Input: s = "zzzzzzz"
Output: z*z*z
Explanation: The string can be encrypted in 2 ways: "z*z*z" and "z**zzz". Out of the two "z*z*z" is smaller in length.
Constraints: 
1 ≤ |s| ≤ 105
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
void computeLPS(string &s, vector<int> &lps)
{
    int n = s.size();
    lps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int len = lps[i - 1];
        while (len > 0 && s[i] != s[len])
        {
            len = lps[len - 1];
        }
        if (s[i] == s[len])
        {
            len++;
        }
        lps[i] = len;
    }
}
string compress(string &s)
{
    int n = s.size();
    if (n == 1)
        return s;
    vector<int> lps(n);
    computeLPS(s, lps);
    stack<char> st;
    for (int i = n - 1; i > 0; i--)
    {
        int len = i + 1;
        if (len % 2 == 1)
        {
            st.push(s[i]);
            continue;
        }
        int longestPrefixSuffix = lps[i];
        int blockLength = len - longestPrefixSuffix;
        bool canCompress = false;
        if (longestPrefixSuffix * 2 >= len &&
            len % blockLength == 0 &&
            (len / blockLength) % 2 == 0)
        {
            canCompress = true;
        }
        if (canCompress)
        {
            st.push('*');
            i = len / 2;
        }
        else
        {
            st.push(s[i]);
        }
    }
    string ans;
    ans.push_back(s[0]);
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    string result = compress(s);
    cout << result << endl;
    return 0;
}