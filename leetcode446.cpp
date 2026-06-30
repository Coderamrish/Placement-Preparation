/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
Approach using the two pointer with the sliding window where TC:O(n) SC:O(1)
Algorithm:
1. use the two pointer l and r
2. maintain the frequency count of all 3 strings a, b, c
3. Expand r until the window is valid
4. once valid :
Add (n - r) to answer
then shrink the window from left.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
int numberofString(string s) {
    int n = s.size();
    int cnt[3] = {0, 0, 0};
    int left = 0, result = 0;
for(int right = 0; right < s.size(); ++right) {
cnt[s[right] - 'a']++;
while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
result += (s.size() - right);
cnt[s[left] - 'a']--;
left++;
}
}
return result;
}
int main() {
    string s;
    getline(cin, s);
    cout << numberofString(s);
    return 0;
}