/*
You are given three integers n, l, and r.

A ZigZag array of length n is defined as follows:

Each element lies in the range [l, r].
No two adjacent elements are equal.
No three consecutive elements form a strictly increasing or strictly decreasing sequence.
Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo 109 + 7.

A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

Example 1:

Input: n = 3, l = 4, r = 5

Output: 2

Explanation:

There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

[4, 5, 4]
[5, 4, 5]
Example 2:

Input: n = 3, l = 1, r = 3

Output: 10

Explanation:

​​​​​​​There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

[1, 2, 1], [1, 3, 1], [1, 3, 2]
[2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
[3, 1, 2], [3, 1, 3], [3, 2, 3]
All arrays meet the ZigZag conditions.

 

Constraints:

3 <= n <= 109
1 <= l < r <= 75​​​​​​​
1. Shift the RangeThe absolute values of $l$ and $r$ do not affect the count, only the number of choices matters. We can map the range $[l, r]$ to $[1, K]$, where $K = r - l + 1$.2. Define the DP StateTo ensure the ZigZag property, when we append a new element, we need to know:The value of the current last element $v$ ($1 \le v \le K$).The direction of the last transition:Direction 0 (Down): The previous element was greater than $v$ ($a_{i-1} > v$). The next element $u$ must be greater than $v$ ($u > v$).Direction 1 (Up): The previous element was smaller than $v$ ($a_{i-1} < v$). The next element $u$ must be smaller than $v$ ($u < v$).This gives us a total of $2K$ states.3. Transition MatrixFrom state $(v, 0)$, we can transition to $(u, 1)$ for all $u > v$.From state $(v, 1)$, we can transition to $(u, 0)$ for all $u < v$.We can form a transition matrix $M$ of size $2K \times 2K$.4. Base Case (Length = 2)For an array of length 2:Ways to be in state $(v, 0)$ (arrived via Down): $K - v$ (any start element from $v+1$ to $K$).Ways to be in state $(v, 1)$ (arrived via Up): $v - 1$ (any start element from $1$ to $v-1$).We can initialize our base vector $V_2$ with these counts, and then compute $V_n = M^{n-2} \times V_2$ using binary exponentiation.
*/
#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 1e9 + 7;
vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int size) {
    vector<vector<long long>> C(size, vector<long long>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int k = 0; k < size; ++k) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < size; ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}
vector<vector<long long>> power(vector<vector<long long>> A, long long p, int size) {
    vector<vector<long long>> res(size, vector<long long>(size, 0));
    for (int i = 0; i < size; ++i) res[i][i] = 1;
    while (p > 0) {
        if (p & 1) res = multiply(res, A, size);
        A = multiply(A, A, size);
        p >>= 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    int l, r;
    if (cin >> n >> l >> r) {
        int K = r - l + 1;
        int size = 2 * K;
        vector<long long> V2(size, 0);
        for (int v = 1; v <= K; ++v) {
            V2[v - 1] = K - v;     
            V2[K + v - 1] = v - 1; 
        }
        vector<vector<long long>> M(size, vector<long long>(size, 0));
        for (int v = 1; v <= K; ++v) {
            for (int u = v + 1; u <= K; ++u) {
                M[K + u - 1][v - 1] = 1;
            }
            for (int u = 1; u < v; ++u) {
                M[u - 1][K + v - 1] = 1;
            }
        }
        M = power(M, n - 2, size);
        long long total_valid = 0;
        for (int i = 0; i < size; ++i) {
            long long ways = 0;
            for (int j = 0; j < size; ++j) {
                ways = (ways + M[i][j] * V2[j]) % MOD;
            }
            total_valid = (total_valid + ways) % MOD;
        }
        cout << total_valid << "\n";
    }
    return 0;
}