/*
There are N houses arranged in a straight line.Each house must be painted using one of C available
colors
The cost of painting the i-th house with the j-th color is given by cost[i][j].
The folowing conditions must be statisfied.
1. Every house must be painted exactly one color.
2. No two adjacent houses can have thesame color.
3. the totla painting cost must not exceed the given budget B.
your task is to determine the minimum total painting cost.
if it is impossible to paint all the houses within the given budget, print -1.
Input format:
The first line contains an integer N, the number of houses.
The second line contains  an integer C, the number of available colors.
the third line contains an integer B, the maximum allowed budget.
output Format:
Print a single integer:
The minimum total painting cost if it does not exceed B
otherwise print -1.
Constraints:
1 <= N <= 1000
2 <= C <= 50
1 <= B <= 10 ^18
1 <= cost[i][j] <= 10^9
sample input 1:
3
3
20
1 5 3
2 9 4
3 1 7
sample output1 :
6
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int N, C;
    long long B;
    if(!(cin >> N >> C >> B)) return 0;
    vector<vector<long long>>cost(N, vector<long long>(C));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> cost[i][j];
        }
    }
    vector<long long> prev_dp(C);
    for(int j = 0; j < C; ++j) {
        prev_dp[j] = cost[0][j];
    }
    for(int i = 1; i < N; ++i) {
        vector<long long> curr_dp(C, -1);
        for(int j = 0; j < C; ++j) {
            long long min_prev = -1;
            for(int k = 0; k < C; ++k) {
                if(k == j) continue;
                if(min_prev == -1 || prev_dp[k] < min_prev) {
                    min_prev = prev_dp[k];
                }
            }
            curr_dp[j] = cost[i][j] + min_prev;
        }
        prev_dp = curr_dp;
    }
    long long min_total_cost = prev_dp[0];
    for(int j = 1; j < C; ++j) {
        min_total_cost = min(min_total_cost, prev_dp[j]);
    }
    if(min_total_cost <= B) {
        cout << min_total_cost << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}

// 2nd idea optimize tc :O(N * C) SC:O(C)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, C;
    long long B;
    if (!(cin >> N >> C >> B)) return 0;
    vector<vector<long long>> cost(N, vector<long long>(C));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> cost[i][j];
        }
    }
    vector<long long> prev_dp(C);
    int min1_idx = -1, min2_idx = -1;
    for (int j = 0; j < C; ++j) {
        prev_dp[j] = cost[0][j];
        if (min1_idx == -1 || prev_dp[j] < prev_dp[min1_idx]) {
            min2_idx = min1_idx;
            min1_idx = j;
        } else if (min2_idx == -1 || prev_dp[j] < prev_dp[min2_idx]) {
            min2_idx = j;
        }
    }
    for (int i = 1; i < N; ++i) {
        vector<long long> curr_dp(C);
        int next_min1_idx = -1, next_min2_idx = -1;
        for (int j = 0; j < C; ++j) {
            if (j == min1_idx) {
                curr_dp[j] = cost[i][j] + prev_dp[min2_idx];
            } else {
                curr_dp[j] = cost[i][j] + prev_dp[min1_idx];
            }
            if (next_min1_idx == -1 || curr_dp[j] < curr_dp[next_min1_idx]) {
                next_min2_idx = next_min1_idx;
                next_min1_idx = j;
            } else if (next_min2_idx == -1 || curr_dp[j] < curr_dp[next_min2_idx]) {
                next_min2_idx = j;
            }
        }
        prev_dp = move(curr_dp);
        min1_idx = next_min1_idx;
        min2_idx = next_min2_idx;
    }
    long long min_total_cost = prev_dp[min1_idx];
    if (min_total_cost <= B) {
        cout << min_total_cost << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}