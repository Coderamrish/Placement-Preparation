/*
Given a bag of size w kg and you are provided costs of packets different weights of oranges in array cost[], find the minimum total cost to buy exactly w kg oranges

The cost of 1 kg orange is present at index 0 and in general arr[i] has cost of (i+1) kg orange.
cost[i] = -1 means that 'i+1' kg packet of orange is unavailable.
If it is not possible to buy exactly w kg oranges then return -1. It may be assumed that there is an infinite supply of all available packet types.
Examples:

Input: cost[] = [20, 10, 4, 50, 100], w = 5
Output: 14
Explanation: The minimum cost is 14 by purchasing a 2kg packet for 10 and a 3kg packet for 4.
Input: cost[] = [-1, -1, 4, 3, -1], w = 5
Output: -1
Explanation: It is not possible to buy 5 kgs.
Constraints:
1 ≤ cost.size(), w ≤ 2*103
1 ≤ cost[i] ≤ 105
Approach - space optimization dp (1D Dp unbounded knapsack) TC:O(n * w) SC:O(w)
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minimumCost(int w, vector<int>& cost) {
    vector<int>dp(1 + w, INT_MAX);
    int n = cost.size();
    dp[0] = 0;
    for(int i = 1; i <= w; i++) {
        int min_cost = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(cost[j] != 0 && (j + 1) <= i &&dp[i - (j + 1)] != INT_MAX) {
                min_cost = min(min_cost, cost[j]+ dp[i- (j + 1)]);
            }
        }
        dp[i] = min_cost;
    }
    return (dp[w] == INT_MAX) ? -1 : dp[w];
}
int main() {
    int w;
    cin >> w;
    int n;
    cin >> n;
    vector<int>cost(n);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cout << minimumCost(w, cost);
    return 0;
}