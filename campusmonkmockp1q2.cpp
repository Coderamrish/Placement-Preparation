/*
check if string is decomposable into value equal substring
A value -equal string is a string where all characters are the same.
for ex:- "1111" and "33" are value- equal strings
in contrast, "123" is not a value equal string.
given a digit string s, decompose the string into some numbers of consective
value -equal substrings where exactly one substring has a length of 2 and the
remaining substring have a length of 3.
return true if you can decomse s according to the above rules otherwise, return false.
A substring is a continous sequence of characters in a string
ex1:
input:s = "000111000"
output: false
*/
#include<iostream>
#include<string>
using namespace std;
bool isDecomposable(string s) {
    int n = s.length();
    int i = 0;
    bool two = false;
    while(i < n) {
        int j = i;
        while(j < n && s[j] == s[i]) {
            j++;
        }
        int len = j - i;
      int rem = len % 3;
      if(rem == 1) {
        return false;
      }  else if(rem == 2) {
        if(two) {
            return false;
        }
        two = true;
      }
      i = j;
    }
    return two;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if(isDecomposable(s)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}