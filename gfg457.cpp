/*
Given an integer array arr[], where arr[i] denotes the number of tickets available with the i-th ticket seller.

The price of each ticket is equal to the number of tickets remaining with that seller at the time of sale.
A seller can sell at most one ticket at a time, and after each sale, the price of the next ticket from that seller decreases by 1.
You are allowed to sell at most k tickets in total.
Find the maximum amount that can be earned by selling the tickets. Return the answer modulo 109+7.

Examples:

Input: arr[] = [4, 3, 6, 2, 4], k = 3
Output: 15
Explanation: One optimal sequence is to sell two tickets from the seller with 6 tickets and one ticket from a seller with 4 tickets. This gives a total earning of 6 + 5 + 4 = 15.
Input: arr[] = [5, 3, 5, 2, 4, 4], k = 2
Output: 10
Explanation: One optimal sequence is to sell one ticket each from the two sellers with 5 tickets, earning 5 + 5 = 10.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i], k ≤ 106
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> arr(N);
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }
    int K;
    cin >> K;
    const int MOD = 1000000007;
    long long ans = 0;
    while (K > 0 && !pq.empty()) {
        int curr = pq.top();
        pq.pop();
        ans = (ans + curr) % MOD;
        curr--;
        if (curr > 0)
            pq.push(curr);
        K--;
    }
    cout << ans % MOD;
    return 0;
}