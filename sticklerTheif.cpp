/*
6. Stickler Thief
Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot.
Given an array, arr[] where arr[i] represents the amount of money in the i-th house. Determine the maximum amount he can loot.
Examples:
Input: arr[] = [6, 7, 1, 3, 8, 2, 4]
Output: 19
Explanation: Maximum amount he can get by looting 1st, 3rd, 5th and 7th house, which is 6 + 1 + 8 + 4 = 19.

Test Case	Input String	Expected Output
                    1                             [5, 3, 4, 11, 2]                      16
                    2                          [6, 7, 1, 3, 8, 2, 4]                 19
                    3                               [1,3,4,5]                                8
                    4                                [7,1,7]                                  14
                    5                                [1,2,3,4]                               6


Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
Approach - using the dp it's the classic house robber problem For every house $i$, the thief has two choices:Rob house $i$: If he robs this house, he cannot rob house $i-1$. His total loot will be the value of the current house plus the maximum loot possible up to house $i-2$.Skip house $i$: If he skips this house, his total loot will be the maximum loot possible up to house $i-1$.Therefore, the recurrence relation is:$$\text{dp}[i] = \max(\text{dp}[i-1], \text{arr}[i] + \text{dp}[i-2])$$Instead of using a full DP array which takes $\mathcal{O}(N)$ space, we can optimize the space complexity to $\mathcal{O}(1)$ by keeping track of only the last two maximum values (prev1 and prev2) as we iterate through the array.
TC:O(n) SC:O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<string>
#include<sstream>
using namespace std;
int maxLoots(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if(n == 1) return arr[0];
int prev2 = 0;
int prev1 = arr[0];
for(size_t i = 1; i < n; i++) {
    int curr = max(prev1, arr[i] + prev2);
    prev2 = prev1;
    prev1 = curr;
}
return  prev1;
}
int main() {
    string input;
    if(!getline(cin, input)) return 0;
    for(char &c : input) {
        if(c == '[' || c == ']' || c == ',')
        c = ' ';
    }
    vector<int>arr;
    stringstream ss(input);
    int num;
    while(ss >> num) {
        arr.push_back(num);
    }
    cout << maxLoots(arr);
    return 0;
}