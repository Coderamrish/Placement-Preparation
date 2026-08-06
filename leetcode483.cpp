/*
You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.
Example 1:
Input: n = 10, t = 2
Output: 10
Explanation:
The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.
Example 2:
Input: n = 15, t = 3
Output: 16
Explanation:
The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.
Constraints:
1 <= n <= 100
1 <= t <= 10
*/
#include<bits/stdc++.h>
using namespace std;
int digitproduct(int n, int t) {
    while(true) {
        int num = n;
        int product = 1;
        while(num > 0) {
            product *= (num % 10);
            num/= 10;
        }
        if(product % t == 0) return n;
        n++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    cout << digitproduct(n, t) << endl;
    return 0;
}