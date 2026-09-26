/*
Given the area of Small, Medium, and Large pizzas as s, m, and l units, and their respective costs as cs, cm, and cl, find the minimum amount of money required to buy pizzas whose total area is at least x. You may buy any number of pizzas of each type.
Examples:
Input: x = 16, s = 3, m = 6, l = 9, cs = 50, cm = 150, cl = 300
Output: 300
Explanation: We want at least 16 sq. units of Pizza. 
One unit of each s, m and l = 3 + 6 + 9 = 18 sq units, Cost = 500. 
6 units of s = 18 sq units, Cost = 300 
2 units of l = 18 sq units, Cost = 600 etc. 
Of all the Arrangements, Minimum Cost is Rs. 300.
Input: x = 10, s = 1, m = 3, l = 10, cs = 10, cm = 20, cl = 50
Output: 50
Explanation: Of all the Arrangements possible, Minimum Cost is Rs. 50.
Constraints:
1 ≤ x ≤ 500
1 ≤ s ≤ m ≤ l ≤ 100
1 ≤ cs ≤ cm ≤ cl ≤ 100
*/
#include <bits/stdc++.h>
using namespace std;
int minimumCost(int x, int s, int m, int l,
                int cs, int cm, int cl) {
    int limit = x + l;
    vector<int> dp(limit + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= limit; i++) {
        if (dp[i] == INT_MAX)
            continue;
        if (i + s <= limit)
            dp[i + s] = min(dp[i + s], dp[i] + cs);
        if (i + m <= limit)
            dp[i + m] = min(dp[i + m], dp[i] + cm);
        if (i + l <= limit)
            dp[i + l] = min(dp[i + l], dp[i] + cl);
    }
    int res = INT_MAX;
    for (int i = x; i <= limit; i++)
        res = min(res, dp[i]);
    return res;
}
int main() {
    int x = 16;
    int s = 3, m = 6, l = 9;
    int cs = 50, cm = 150, cl = 300;
    cout << minimumCost(x, s, m, l, cs, cm, cl) << endl;
    return 0;
}