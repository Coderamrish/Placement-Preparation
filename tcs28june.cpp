/*
Create a class that implements a Stack with following method
push(value:string)
pop()
evaluate()
the stack should be encapsulated , meaning the stack data should be private and can be only accessed through these methods
use this class to evaluate a postfix expression
it is guarenteed that the input expression is always valid
input format:
first line containsd an integer N, representing number of tokens
second line contains N space separated tokens(numbers and operators)
+
-
*
/
output format:
print the result of postfix expression
Example1 :
Input:
5
13 5 + 4 -
output:
14
Example2:
7
5 6 2 + * 4 -
output:
36
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
class Stack{
    private:
    vector<string>st;
    public:
    void push(string value) {
        st.push_back(value);
    }
    string pop() {
string val = st.back();
st.pop_back();
return val;
    }
    int evaluate(vector<string>& tokens)  {
for(string token : tokens) {
    if(token == "+" || token == "-" || token == "*" || token == "/") {
        int b = stoi(pop());
        int a = stoi(pop());
        if (token == "+") 
            push(to_string(a + b));
            else if(token == "-")
            push(to_string(a - b));
            else if(token == "*")
            push(to_string(a * b));
            else if(token == "/")
            push(to_string(a / b));
    } else {
        push(token);
    }
}
return stoi(pop());
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    if(!(cin >> N)) return 0;
    string dummy;
    getline(cin, dummy);
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> tokens;
    string token;
   while(tokens.size() < N && ss >> token) {
        tokens.push_back(token);
    }
    Stack s;
    cout << s.evaluate(tokens) << endl;
    return 0;
}