/*
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
The digit sum of n (the sum of its digits).
The digit product of n (the product of its digits).
Return true if n is divisible by this sum; otherwise, return false.
Example 1:
Input: n = 99
Output: true
Explanation:
Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.
Example 2:
Input: n = 23
Output: false
Explanation:
Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 * 3 = 6) of its digits (total 11), the output is false.
Constraints:
1 <= n <= 106
*/
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int tempN = n;
        while (tempN > 0) {
            int digit = tempN % 10;
            digitSum += digit;
            digitProduct *= digit;
            tempN /= 10;
        }
        int totalSum = digitSum + digitProduct;
        if (totalSum == 0)
            return false;
        return (n % totalSum == 0);
    }
};
int main() {
    int n;
    cin >> n;
    Solution obj;
    if (obj.checkDivisibility(n))
        cout << "true";
    else
        cout << "false";
    return 0;
}