/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000
Approach - using the While b != 0:
carry = (a & b) << 1
a = a ^ b
b = carry
When no carry remains, a is the result
TC:O(n) SC:O(1)
*/
#include<iostream>
using namespace std;
int get(int a, int b) {
    while(b != 0) {
        unsigned carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    if(!(cin >> a >> b)) {
        cout << get(a , b) << "\n";
    }
    return 0;
}