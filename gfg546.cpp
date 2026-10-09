/*
Given a number n. Find the minimum number of operations required to reach n starting from 0.

You have two operations available:

Double the number
Add one to the number
Examples:

Input: n = 8
Output: 4
Explanation: 0 + 1 = 1 --> 1 + 1 = 2 --> 2 * 2 = 4 --> 4 * 2 = 8.
Input: n = 7
Output: 5
Explanation: 0 + 1 = 1 --> 1 + 1 = 2 --> 1 + 2 = 3 --> 3 * 2 = 6 --> 6 + 1 = 7.
Constraints:

1 ≤ n ≤ 106
*/
#include <iostream>
using namespace std;
int minOperation(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n--;
        cnt++;
    }
    return cnt;
}
int main()
{
    int n = 7;
    cout << minOperation(n);
    return 0;
}