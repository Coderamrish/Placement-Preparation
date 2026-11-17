/*
Given a string s made of two characters of 'x' and 'y'.  The task is to verify whether s is made by concatenating substrings that follow the pattern xnyn (equal number of y's follow equal number of x's).
Examples:
Input: s = "xxyyxy" 
Output: true
Explanation: The string can be split into "xxyy" + "xy". Both substrings contain an equal number of consecutive 'x' and 'y' characters.
Input: s = "xyx"
Output: false
Explanation: The last 'x' cannot form a valid substring because it is not followed by a matching 'y'. 
Constraints:
1 ≤ s.size() ≤ 105
s consists only of the characters x and y
*/

#include <iostream>
#include <string>
using namespace std;
bool findPattern(string &s)
{
    int n = s.size();
    if (n % 2)
    {
        return false;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt < 0)
        {
            return false;
        }
    }
    return cnt == 0;
}
int main()
{
    string s = "xxyyxy";
    cout << (findPattern(s) ? "true" : "false") << endl;
    return 0;
}