/*
Problem Statement: Given an array prices where prices[i] is the price of a stock on day i, find the maximum profit achievable from a single buy-then-sell transaction. You must buy before you sell. If no profit can be made, print 0. 
For example — for prices [7, 1, 5, 3, 6, 4], buying on day 1 (price 1) and selling on day 4 (price 6) yields a profit of 5, which is the maximum possible. 
Requirement: Your solution must run in O(N) time in a single pass. A nested-loop O(N²) approach that compares every buy-sell pair will time out for the upper input size. 
Constraints: 
1 ≤ N ≤ 10⁵
0 ≤ prices[i] ≤ 10⁴
Input Format: 
Line 1: An integer N (the number of days). Line 2: N space-separated integers — the daily prices. 
Output Format: 
Print a single integer — the maximum profit, or 0 if no profitable transaction exists. 
Explanation: 
Track the minimum price seen so far and the best profit achievable: 
Initialise minPrice to the first day's price and maxProfit to 0.
For each subsequent price p: compute the profit if we sold today (p − minPrice); update maxProfit = max(maxProfit, p − minPrice); update minPrice = min(minPrice, p).
After the single pass, maxProfit holds the answer.
The key insight is that for any potential sell day, the best buy day is the cheapest day at or before it — so tracking the running minimum is sufficient. If prices only ever decline, maxProfit stays at 0. 
Time complexity: O(N). 
Space complexity: O(1). 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int minPrice = arr[0];
    int maxProfit = 0;
    for(int i = 1; i < N; i++) {
       
        maxProfit = max(maxProfit, arr[i] - minPrice);
        minPrice = min(minPrice, arr[i]);
    }
    cout << maxProfit << "\n";
    return 0;
}