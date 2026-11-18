/*
Given two integers l and r, find the bitwise XOR of all integers in the range [l, r] (both inclusive).
Examples:
Input: l = 4, r = 8 
Output: 8 
Explanation: The XOR of all integers from 4 to 8 is (4 xor 5 xor 6 xor 7 xor 8) = 8.
Input: l = 2, r = 4
Output: 5
Explanation: The XOR of all integers from 2 to 4 is (2 xor 3 xor 4) = 5.
Input: l = 5, r = 9
Output: 5
Explanation: The XOR of all integers from 5 to 9 is (5 xor 6 xor 7 xor 8 xor 9) = 5.
Constraints:
1 ≤ l ≤ r ≤ 109
*/
#include <iostream>
using namespace std;
int computeXOR(int n) {
    int rem = n % 4;
    if (rem == 0)
        return n;
    if (rem == 1)
        return 1;
    if (rem == 2)
        return n + 1;
    return 0;
}
int findXOR(int l, int r) {
    int xorR = computeXOR(r);
    int xorLMinus1 = computeXOR(l - 1);
    return xorR ^ xorLMinus1;
}
int main() {
    int l = 4, r = 8;
    cout << findXOR(l, r) << "\n";
    return 0;
}