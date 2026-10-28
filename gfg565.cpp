/*
Consider a string s formed by concatenating the decimal representations of all positive integers in order:
s = "12345678910111213141516171819202122232425262728293031..."
Given an integer n, find the nth character (1-based indexing) in the string s.
Examples:
Input: n = 10
Output: '1'
Explanation: The 10th in "1234567891.." character is '1'.
Input: n = 11
Output: '0'
Explanation: The 11th character in "12345678910.."  is '0'.
Constraints:
1 ≤ n ≤ 109
*/
#include <iostream>
using namespace std;
char nthCharacter(int n)
{
    int len = 1;
    long long count = 9;
    long long start = 1;
    while (n > len * count)
    {
        n -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }
    long long number = start + (n - 1) / len;
    int digitIndex = (n - 1) % len;
    long long divisor = 1;
    for (int i = 0; i < len - digitIndex - 1; i++)
    {
        divisor *= 10;
    }
    int digit = (number / divisor) % 10;
    return '0' + digit;
}
int main()
{
    int n = 10;
    cout << "'" << nthCharacter(n) << "'";
    return 0;
}