/*
Given a number n, find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

Examples:

Input: n = 10
Output: 1
Explanation: There is only one way, 10 = 1+2+3+4.
Input: n = 15
Output: 3
Explanation: There are 3 ways, (15 = 1+2+3+4+5), (15 = 4+5+6) and (15 = 7+8).
Constraints:
1 ≤ n ≤ 108
Approach - using the two pointer algorithm we initialize left = 1, right = 1, cnt = 0, sum = 0, and we keep moves the right pointer until sum is less than n, if sum is equal to n we increase the cnt and move left poniter .
TC:O(n) SC:O(1)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cntways(int n) {
    int left = 1, right = 1, cnt = 0, sum = 0;
    while (left < n) {
        if(sum < n) {
            sum += right;
            right++;
        } else if(sum > n) {
            sum -= left;
            left++;
        } else {
            cnt++;
            sum -= left;
            left++;
        }
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;
    cout << cntways(n);
    return 0;
}