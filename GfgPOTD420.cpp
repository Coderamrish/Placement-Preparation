/*
Given a string s consisting of n lowercase characters. Return the lexicographically smallest string after removing exactly k characters from the string. But you have to correct the value of k, i.e., if the length of the string is a power of 2, reduce k by half, else multiply k by 2. You can remove any k characters.

Note: If it is not possible to remove k (the value of k after correction) characters or if the resulting string is empty return -1.
Examples:
Input: s = "fooland", k = 2
Output: "and" 
Explanation: As the size of the string = 7 which is not a power of 2, hence k = 4. After removing 4 characters from the given string, the lexicographically smallest string is "and".
Input: s = "code", k = 4
Output: "cd"
Explanation: As the length of the string = 4, which is 2 to the power 2, hence k = 2. Hence, lexicographically smallest string after removal of 2 characters is "cd".
Constraints:
1 ≤ n ≤ 105
1 ≤ k ≤ 105
Approach 1 - brute force nested loops tc:O(n^2) SC:O(n)
Approach 2 - using stack TC:O(n + k) SC:O(n)
*/
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
string LexicographicallySmallest(string s, int k) {
    string ans = "";
    int l = s.length();
    if(l &(l - 1)) k += k;
    else k /= 2;
    if(k >= l) return "-1";
    stack<char>st;
    for(int i = 0; i < l; i++) {
        while(!st.empty() &&  k > 0 && st.top() > s[i]) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    if(k > 0) 
    while(k--)
    st.pop();
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << LexicographicallySmallest(s, k) << endl;
    return 0;
}
