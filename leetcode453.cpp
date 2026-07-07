/*
You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

 

Example 1:

Input: n = 10203004

Output: 12340

Explanation:

The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
Therefore, the answer is x * sum = 1234 * 10 = 12340.
Example 2:

Input: n = 1000

Output: 1

Explanation:

The non-zero digit is 1, so x = 1 and sum = 1.
Therefore, the answer is x * sum = 1 * 1 = 1.
 

Constraints:

0 <= n <= 109
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long x = 0;
    int sum = 0;
    vector<int> digits;
    while (n > 0) {
        int d = n % 10;
        if (d != 0) {
            digits.push_back(d);
            sum += d;
        }
        n /= 10;
    }
    for (int i = digits.size() - 1; i >= 0; i--) {
        x = x * 10 + digits[i];
    }
    cout << x * sum;
    return 0;
}