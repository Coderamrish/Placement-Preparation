/*
Consider an array a[] = [1, 2, 3, ..., n] and a permutation b[] of size n containing all integers from 1 to n exactly once.

The array b[] defines a rearrangement operation.
During a single operation, every element at position i in a[] moves to position b[i] (1-based indexing).
We must do at least one operation on a[].
Find the minimum number of operations required for all elements to return to their original positions simultaneously, i.e., for a[] to become: [1, 2, 3, ..., n] again.

Note:  The answer can be large, so return the answer modulo 10^9+7.

Examples:

Input: b[] = [1, 2, 3]
Output: 1
Explanation: Initially, a[] = [1, 2, 3] and b[] = [1, 2, 3]
After one operation:
a[1] = 1 goes to position 1 as b[1] = 1.
a[2] = 2 goes to position 2.
a[3] = 3 goes to position 3.
so, now a[] becomes [1, 2, 3].
All elements remain at their original positions. Hence, the answer is 1.
Input: b[] = [2, 3, 1, 5, 4]
Output: 6
Explanation: The sequence of arrays obtained after each operation is:
Initially : [1, 2, 3, 4, 5]
1 : [3, 1, 2, 5, 4]
2 : [2, 3, 1, 4, 5]
3 : [1, 2, 3, 5, 4]
4 : [3, 1, 2, 4, 5]
5 : [2, 3, 1, 5, 4]
6 : [1, 2, 3, 4, 5]
After 6 operations, all elements return to their original positions simultaneously. Therefore, the answer is 6.
Constraints:
1 ≤ n ≤ 104
a.size() = b.size() = n
b[] is a permutation of integers from 1 to n.

Approach - Using Cycle Length and Prime Factorization - O(n log n) Time and O(n) Space
The idea is to view the given rearrangement as a permutation of positions. Since a permutation consists of one or more disjoint cycles, the problem reduces to determining after how many operations all these cycles return to their starting positions simultaneously. This can be obtained from the cycle lengths.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int MOD = 1000000007;
long long modPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<bool> visited(n, false);
    vector<int> cycles;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int current = i;
            int length = 0;
            while (!visited[current]) {
                visited[current] = true;
                current = p[current] - 1; 
                length++;
            }
            cycles.push_back(length);
        }
    }
    vector<int> spf(n + 1);
    for (int i = 0; i <= n; i++)
        spf[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    unordered_map<int, int> maxPower;
    for (int len : cycles) {
        unordered_map<int, int> freq;
        while (len > 1) {
            int prime = spf[len];
            int count = 0;
            while (len % prime == 0) {
                len /= prime;
                count++;
            }
            freq[prime] = count;
        }
        for (auto &it : freq) {
            maxPower[it.first] =
                max(maxPower[it.first], it.second);
        }
    }
    long long answer = 1;
    for (auto &it : maxPower) {
        answer = (answer *
                 modPow(it.first, it.second)) % MOD;
    }
    cout << answer;
    return 0;
}