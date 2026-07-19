/*
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
 
*/
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    vector<bool> used(26, false);
    stack<char>st;
    for(char ch : s) {
        freq[ch - 'a']++;
    }
    for(char ch : s) {
        freq[ch - 'a']--;
    if(used[ch - 'a']) {
        continue;
    }
    while(!st.empty() && st.top() > ch && freq[st.top() - 'a'] > 0) {
        used[st.top() - 'a'] = false;
        st.pop();
    }
    st.push(ch);
    used[ch - 'a'] = true;
}
string ans;
while(!st.empty()) {
    ans += st.top();
    st.pop();
}
reverse(ans.begin(), ans.end());
cout << ans;
return 0;
}