/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
Approach using the stack based where we keep track of the opening brackets, when a closing brackets appears Stack must not be empty, top of the stack must match the closing brackets, at the end stack must be empty
TC:O(n) SC:O(n)
*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    if(!(cin >> s)) return 0;
    if(s.length() % 2 != 0) {
        cout << "false";
        return 0;
    }
    stack<char>st;
    for(char ch : s) {
        if(ch == '(') st.push(')');
        else if(ch == '{') st.push('}');
        else if(ch == '[') st.push(']');
        else {
            if(st.empty() || st.top() != ch) {
                cout << "false\n";
                return 0;
            }
            st.pop();
        }
    }
    cout << (st.empty() ? "true\n" : "false\n");
    return 0;
}