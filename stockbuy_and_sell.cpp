/*
1.	Stock Buy and Sell - Max one Transaction Allowed

Given an array prices[] of non-negative integers, representing the prices of the stocks on different days, find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

Examples:
Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
Output: 8
Explanation: Buy for price 1 and sell for price 9. 

Test Case	Input String	Expected Output
1	[7, 10, 1, 3, 6, 9, 2]
	8
2	[7, 6, 4, 3, 1]	0
3	[1, 3, 6, 9, 11]	10
4	[2, 3, 6, 9, 11]	9
5	[7, 6, 4, 3, 2]	0
Approach - one traversal solution TC:O(n) SC:O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<sstream>
using namespace std;
int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
    int minPrice = prices[0], res = 0;
    for(int i = 1; i < prices.size(); i++) {
minPrice = min(minPrice, prices[i]);
res = max(res, prices[i] - minPrice);
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    cout << maxProfit(prices);
    return 0;
}