/*
Given two strings s1 and s2, and two integers costS1 and costS2, where costS1 is the cost of deleting one character from s1 and costS2 is the cost of deleting one character from s2, find the minimum cost required to make the two strings identical.

You can delete any number of characters from either string, but the order of the remaining characters must be preserved.

Examples:

Input: s1 = "abcd", s2 = "acdb", costS1 = 10, costS2 = 20
Output: 30
Explanation: Delete 'b' from both strings to obtain "acd". The total cost is 10 + 20 = 30.
Input: s1 = "ef", s2 = "gh", costS1 = 10, costS2 = 20
Output: 60
Explanation: The two strings have no common characters, so delete all characters from both strings. The total cost is (2 × 10) + (2 × 20) = 60.
Constraints:

1 ≤ s1.size(), s2.size() ≤ 1000
1 ≤ costS1, costS2 ≤ 105
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int findMinCost(string &s1, string &s2, int costS1, int costS2)
{
    if (s1.length() < s2.length())
    {
        swap(s1, s2);
        swap(costS1, costS2);
    }
    int n = s1.length(), m = s2.length();
    vector<int> prev(m + 1), curr(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        swap(prev, curr);
    }
    int lcsLength = prev[m];
    return (n - lcsLength) * costS1 + (m - lcsLength) * costS2;
}
int main()
{
    string s1 = "abcd", s2 = "acdb";
    int costS1 = 10, costS2 = 20;
    cout << findMinCost(s1, s2, costS1, costS2);
    return 0;
}