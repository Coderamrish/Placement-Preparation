/*
A historical department has developed a special roman numerical encoding system, in this system:
Every 1000 is represented by the symbol 'M'.
The remaining value(less than 100) is converted using standard Roman numeral rules.
Given an integer N, convert it into its Roman Numeral representation.
standard Roman Symbols
value symbol
1000   M
900    CM
500    D
400    CD
100  C
90    XC
50    L
10    X
9     IX
5     V
4     IV
1     I
Example
input:
10554
output:
MMMMMMMMMMDLIV
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N;
if(!(cin >> N)) return 0;
vector<int> values = {
    1000, 900, 500, 400, 100, 90, 50 , 40, 10, 9, 5, 4 ,1
};
vector<string> symbols = {
    "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
};
string result = "";
for(size_t i = 0; i < values.size(); ++i) {
    while(N >= values[i]) {
        result += symbols[i];
        N -= values[i];
    }
}
cout << result << "\n";
return 0;
}