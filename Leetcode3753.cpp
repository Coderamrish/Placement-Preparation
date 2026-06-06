/*
You are given two integers num1 and num2 representing an inclusive range [num1, num2].
The waviness of a number is defined as the total count of its peaks and valleys:
A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].
Example 1:
Input: num1 = 120, num2 = 130
Output: 3
Explanation:
In the range [120, 130]:
120: middle digit 2 is a peak, waviness = 1.
121: middle digit 2 is a peak, waviness = 1.
130: middle digit 3 is a peak, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.
Example 2:
Input: num1 = 198, num2 = 202
Output: 3
Explanation:
In the range [198, 202]:
198: middle digit 9 is a peak, waviness = 1.
201: middle digit 0 is a valley, waviness = 1.
202: middle digit 0 is a valley, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.
Example 3:
Input: num1 = 4848, num2 = 4848
Output: 2
Explanation:
Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.
Constraints:
1 <= num1 <= num2 <= 1015​​​​​​​

Approach using The DP TC:O(n * d^2) SC:O(N* d^2)
*/
#include<iostream>
#include <string>
#include <vector>
using namespace std;
    pair<long long, long long> memo[20][2][2][12][12];
    string S;
    pair<long long, long long> dfs(int idx, bool tight, bool is_zero, int prev1, int prev2) {
        if (idx == S.length()) {
            return {1, 0}; 
        }
        if (memo[idx][tight][is_zero][prev1 + 1][prev2 + 1].first != -1) {
            return memo[idx][tight][is_zero][prev1 + 1][prev2 + 1];
        }
        int limit = tight ? S[idx] - '0' : 9;
        long long total_count = 0;
        long long total_wave = 0;
        for (int d = 0; d <= limit; ++d) {
            bool new_tight = tight && (d == limit);
            bool new_zero = is_zero && (d == 0); 
            int new_prev1 = prev1;
            int new_prev2 = prev2;
            long long added_wave = 0;
            if (new_zero) {
                new_prev1 = -1;
                new_prev2 = -1;
            } else {
                if (is_zero) { 
                    new_prev1 = d;
                    new_prev2 = -1;
                } else {
                    if (prev2 != -1) {
                        if (prev1 > prev2 && prev1 > d) added_wave = 1;
                        if (prev1 < prev2 && prev1 < d) added_wave = 1;
                    }
                    new_prev2 = prev1;
                    new_prev1 = d;
                }
            }
            auto res = dfs(idx + 1, new_tight, new_zero, new_prev1, new_prev2);
            total_count += res.first;
            total_wave += res.second + res.first * added_wave;
        }
        return memo[idx][tight][is_zero][prev1 + 1][prev2 + 1] = {total_count, total_wave};
    }
    long long solve(long long num) {
        if (num < 100) return 0;
        S = to_string(num);
        for(int i = 0; i < 20; ++i)
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 2; ++k)
                    for(int l = 0; l < 12; ++l)
                        for(int m = 0; m < 12; ++m)
                            memo[i][j][k][l][m] = {-1, -1};
        return dfs(0, true, true, -1, -1).second; 
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
int main() {
    long long num1, num2;
    cin >> num1 >> num2;
    cout << totalWaviness(num1, num2) << endl;
    return 0;
}