/*
Given an integer x, return true if x is a palindrome, and false otherwise.
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Constraints:
-231 <= x <= 231 - 1
Appraoch - If x < 0, return false
If x % 10 == 0 and x != 0, return false
Initialize reversedHalf = 0
While x > reversedHalf:
reversedHalf = reversedHalf * 10 + x % 10
x = x / 10
If x == reversedHalf OR x == reversedHalf / 10, return true
Else return false
TC:Time: O(log₁₀ n)
Space: O(1)
*/
#include<iostream>
using namespace std;
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int x;
   if(!(cin >> x)) return 0;
   if(x < 0 || x % 10 == 0 && x != 0) {
    cout << "false\n";
    return 0;
   }
   int rev = 0;
   while(x > rev) {
    rev = rev * 10 + rev % 10;
    x /= 10;
   }
   if(x == rev || x == rev / 10) {
    cout << "true\n";
   } else {
    cout << "false\n";
   }
   return 0;
}