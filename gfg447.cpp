/*
Given an array arr[] of positive integers and a value k. Return true if the sum of any non-empty subset of the given array is divisible by k otherwise, return false.

Examples:

Input: arr[] = [3, 1, 7, 5] , k = 6
Output: true
Explanation: If we take the subset {7, 5} then sum will be 12 which is divisible by 6.
Input: arr[] = [1, 2, 6] , k = 5
Output: false
Explanation: All possible subsets of the given set are {1}, {2}, {6}, {1, 2}, {2, 6}, {1, 6} and {1, 2, 6}. There is no subset whose sum is divisible by 5.
Constraints:
1 ≤ arr.size(), k ≤ 103
1 ≤ arr[i] ≤ 103
Approach - using the dp Using Modulo States – O(n × k) Time and O(k) Space
Instead of tracking actual subset sums, only their remainders after division by k are maintained. If at any point remainder 0 becomes achievable, it means there exists a subset whose sum is divisible by k. A boolean DP array of size k is used where:  dp[i] = true  means there exists a subset having remainder i when divided by k. For every array element, new modulo values are generated from already achievable remainders. A temporary array is used so that the current element is added only once per iteration.
Also, if the number of elements is greater than k, the answer is immediately true due to the Pigeonhole Principle.

If n > k, return true immediately
Create a boolean dp array of size k
Traverse every element in the array: Generate new modulo sums using existing dp states Store updates temporarily. Merge temporary states into dp
Mark arr[i] % k as achievable
If DP[0] becomes true, return true
Return final value of dp[0]
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
bool carvesSubsetSum(vector<int>& arr, int n, int k) {
    for (int num : arr) {
        if (num % k == 0) return true;
    }
    vector<bool> dp(k, false);
    for (int i = 0; i < n; i++) {
        int current_rem = arr[i] % k;
        if (current_rem == 0) return true;
        for (int j = k - 1; j >= 0; j--) {
            if (dp[j]) {
                int next_rem = (j + current_rem) % k;
                if (next_rem == 0) return true;
                dp[next_rem] = true;
            }
        }
        dp[current_rem] = true;
    }
    return dp[0];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    if (carvesSubsetSum(arr, n, k)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    return 0;
}