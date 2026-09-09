/*
Given a number n, find a number in the range from 1 to n such that its digit sum is maximum. If there are multiple such numbers, return the largest of them.
Examples:
Input: n = 48
Output: 48
Explanation: There are two numbers with maximum digit sum = 12. The numbers are 48 and 39. Since 48 > 39, so 48 is the answer.
Input: n = 90
Output: 89
Explanation: 89 gives us the largest digit sum in the range from 1 to n. Hence the answer is 89. 
Constraints:
1 ≤ n ≤ 109
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMax(int n) {
        string s = to_string(n);
        int d = s.size();
        int totalSum = 0;
        for (char c : s) {
            totalSum += c - '0';
        }
        int ans = n;
        int bestSum = totalSum;
        long long p = 1;
        int suffixSum = 0;
        for (int i = d - 1; i >= 0; i--) {
            int digit = s[i] - '0';
            suffixSum += digit;
            if (digit > 0) {
                long long cand = (n / (p * 10)) * (p * 10);
                cand += (digit - 1) * p;
                cand += p - 1;
                int digitsRight = d - i - 1;
                int curSum =
                    totalSum - suffixSum
                    + (digit - 1)
                    + 9 * digitsRight;
                if (curSum > bestSum ||
                    (curSum == bestSum && cand > ans)) {
                    bestSum = curSum;
                    ans = (int)cand;
                }
            }
            p *= 10;
        }
        return ans;
    }
};
int main() {
    Solution obj;
    int n;
    cin >> n;
    cout << obj.findMax(n) << endl;
    return 0;
}