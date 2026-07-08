/*
You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

For each queries[i], extract the substring s[li..ri]. Then, perform the following:

Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x. The answer is x * sum.
Return an array of integers answer where answer[i] is the answer to the ith query.

Since the answers may be very large, return them modulo 109 + 7.

 

Example 1:

Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]

Output: [12340, 4, 9]

Explanation:

s[0..7] = "10203004"
x = 1234
sum = 1 + 2 + 3 + 4 = 10
Therefore, answer is 1234 * 10 = 12340.
s[1..3] = "020"
x = 2
sum = 2
Therefore, the answer is 2 * 2 = 4.
s[4..6] = "300"
x = 3
sum = 3
Therefore, the answer is 3 * 3 = 9.
Example 2:

Input: s = "1000", queries = [[0,3],[1,1]]

Output: [1, 0]

Explanation:

s[0..3] = "1000"
x = 1
sum = 1
Therefore, the answer is 1 * 1 = 1.
s[1..1] = "0"
x = 0
sum = 0
Therefore, the answer is 0 * 0 = 0.
Example 3:

Input: s = "9876543210", queries = [[0,9]]

Output: [444444137]

Explanation:

s[0..9] = "9876543210"
x = 987654321
sum = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
Therefore, the answer is 987654321 * 45 = 44444444445.
We return 44444444445 modulo (109 + 7) = 444444137.
 

Constraints:

1 <= m == s.length <= 105
s consists of digits only.
1 <= queries.length <= 105
queries[i] = [li, ri]
0 <= li <= ri < m
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MOD = 1000000007;
int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    vector<long long> pow10(n + 1, 1);
    for (int i = 1; i <= n; i++)
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    vector<int> sumD(n + 1, 0), cntN0(n + 1, 0);
    vector<long long> prefNum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int d = s[i - 1] - '0';
        sumD[i] = sumD[i - 1] + d;
        cntN0[i] = cntN0[i - 1] + (d != 0);
        if (d != 0)
            prefNum[i] = (prefNum[i - 1] * 10 + d) % MOD;
        else
            prefNum[i] = prefNum[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int nonZero = cntN0[r + 1] - cntN0[l];
        int digitSum = sumD[r + 1] - sumD[l];
        long long number =
            (prefNum[r + 1] -
             prefNum[l] * pow10[nonZero] % MOD + MOD) % MOD;
        cout << (number * digitSum) % MOD << endl;
    }
    return 0;
}