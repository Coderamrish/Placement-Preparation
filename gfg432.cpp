/*
Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their lengths is maximized. At least one cut is mandatory.

Examples:

Input: n = 2
Output: 1
Explanation: Since 1 cut is mandatory. Maximum obtainable product is 1 * 1 = 1.
Input: n = 5
Output: 6
Explanation: Maximum obtainable product is 2 * 3 = 6.
Constraints:
2 ≤ n ≤ 58
Approach 1 - using the recursion TC:O(2^n) SC:O(n)
Approach 2 - using the dp TC:O(n ^ 2) SC:O(n)
approach 3 - using the mathematical greedy TC:O(n) SC:O(1)
Approach 4 - using the Exponentiation TC:O(log n ) SC:O(1)
*/
// approach 3 - using the mathematical greedy approach 
#include<iostream>
#include<algorithm>
using namespace std;
int maxProduct(int n){
    if(n == 2 || n == 3) {
        return n - 1;
    }
    int product = 1;
    while(n > 4) {
        product *= 3;
        n -= 3;
    }
    return product * n;
}
int main() {
    int n;
    cin >> n;
    cout << maxProduct(n);
    return 0;
}