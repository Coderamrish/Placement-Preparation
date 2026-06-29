/*
Given two arrays a[] and b[] of positive integers of size n and m respectively, where m ≤ n.  You are allowed to insert zeros anywhere into the second array b so that its length becomes equal to n.

The dot product of two arrays of equal length n is defined as: a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].
Return the maximum possible dot product of the two arrays.
Examples :

Input: a[] = [2, 3, 1, 7, 8], b[] = [3, 6, 7]
Output: 107
Explanation: Maximum dot product is obtained after inserting 0 at the first and third positions in array b.
Therefore b becomes [0, 3, 0, 6, 7]. 
Maximum dot product = 2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107. Therefore answer for this test case is 107.
Input: a[] = [1, 2, 3], b[] = [4] 
Output: 12 
Explanation: Maximum dot product is obtained after inserting 0 at the first and second positions in array b.
Therefore b becomes [0, 0, 4]. 
Maximum Dot Product = 1*0 + 2*0 + 3*4 = 12. Therefore answer for this test case is 12.
Constraints:
1 ≤ m ≤ n ≤ 103
1 ≤ a[i], b[i] ≤ 103
Approach - using the dp Create an array dp to store the maximum dot product values.
Initialize all elements of dp to 0.
Iterate over the a array and process each element.
For each element in a, iterate over the b array in reverse order and process each element.
Update dp[j] with the maximum value between the current dp[j] and dp[j - 1] + (a[i - 1] * b[j - 1]).
After the loops, dp[n] will represent the maximum dot product achievable.
Return dp[n] as the result.
TC:O(n*m) SC:O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int>b(m);
    for(int i = 0; i < m; i++) {
cin >> b[i];
    }
    vector<int>dp(m+1, -1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--) {
            dp[j] = max(dp[j], dp[j - 1]+a[i - 1] * b[j - 1]);
        }
    }
    cout << dp[m];
    return 0;
}