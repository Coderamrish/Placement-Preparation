/*
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

 

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
Example 2:

Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
Example 3:

Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
 

Constraints:

costs.length == n
1 <= n <= 105
1 <= costs[i] <= 105
1 <= coins <= 108
approach1 - u8sing the greedy method I used a greedy approach with a counting array to avoid sorting, achieving linear time complexity while always purchasing the cheapest ice cream first.
tc :O(n + maxCost) SC:O(maxcost)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int maxIcecream(vector<int>& costs, int coins) {
    int maxCosts = 0;
    for(int cost : costs) {
        maxCosts = max(maxCosts, cost);
    }
vector<int>count(maxCosts + 1, 0);
for(int cost: costs) {
    count[cost]++;
}
int bars = 0;
for(int cost = 1; cost <= maxCosts && coins >= cost; cost++) {
    if(count[cost] > 0) {
        int canBuy = min(count[cost], coins/cost);
        bars += canBuy;
        coins -= canBuy * cost;
    }
}
return bars;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int n, coins;
        cin >> n >> coins;
        vector<int>costs(n);
        for(int i = 0; i < n; i++) {
            cin >> costs[i];
        }
        cout << maxIcecream(costs, coins) << "\n";
    }
    return 0;
}