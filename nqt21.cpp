/*
Write a program to perform the following operations on a stack.
1. Read an integer n, representing the number of string to be inserted into the stack
2. read n strings and push them onto the stack in given order
3. read an integer m, representing the unmber of element to be removed from the stack
4. pop m elements from stack.
5. print the output in the foloowing ofrmat:
Stack_status_Top_element Elements_left
Stack_status is True if stack is empty after popping, otherwise false.
Top_elements is current top elements of the stack . if stack is empty print -.
Elements_left is number of elements remaining in the stack.
Inputformat:
the first line contains an integer n.
the next line contains one string each
the last line contain an integer m.
output format:
Print the stack status, the top element (or -if the stack is empty), and the number of elements left in the stack.
constraints:
1 <= n <= 100
0 <= m <= n
sample input:
4
A
B
C
D
2
sample outout 
False B 2
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stack<string>st;
for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    st.push(s);
}
int m;
cin >> m;
while(m--) {
    st.pop();
}
if(st.empty()) {
    cout << "True"
    << " "
    << "-"
    << " "
    << 0;
} else {
    cout << "False"
    << " "
    << st.top()
    << " "
    << st.size();
}
return 0;
}
