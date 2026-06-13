/*
Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits. 
Note: Since the anwer can be very large, so return the answer modulo 109+7.
Examples:
Input: n = 2
Output: 6
Explanation: There are 6 sequences of length 2*n, the sequences are 0101, 0110, 1010, 1001, 0000 and 1111.
Input: n = 1
Output: 2
Explanation: There are 2 sequence of length 2*n, the sequence are 00 and 11. 
Constraints:
1 ≤ n ≤ 105

Appraoch 1 - using recursion TC:O(n ^ 3) SC:O(n)
Appraoch 2 - using combinatorics TC:O(n) SC:O(1)
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int MOD = 1e9 + 7;
long long power(long long a, long long b) {
    long long ans = 1;
    while(b) {
        if(b & 1) 
        ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
int computeValue(int n) {
    long long fact1 = 1, fact2 = 1;
    for(int i = 1; i <= 2 * n; i++) fact1 = (fact1 * i) % MOD;
    for(int i = 1; i <= n; i++) fact2 = (fact2 * i) % MOD;
    long long demon = (fact2 * fact2) % MOD;
    long long ans = (fact1 * power(demon, MOD - 2)) % MOD;
    return ans;
}
int main() {
    int n;
    cin >> n;
    cout << computeValue(n) << endl;
    return 0;
}