/*
There are two items A and B with their respective prices. write a program to determine which is more expensive 
conditions:
1 If either price is less than 0, then print "Invalid"
2 if both prices are equal print"Prices Equal"
3 otherwise print the higher price followed by "is more expensive"
Input format:
two integers 
A B
where 
A = price of first item
B = price of second item
output :
"Invalid input" if any price is negative
"Prices Equal" IF  both prices equal
otherwise
<Maximum Price> is more expensive
Example1
input:
10 15
output:
15 is more expensive
Example 2
input:
10 10
output:
Prices Equal
*/
#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B;
    cin >> A >> B;
    if (A < 0 || B < 0) {
        cout << "Invalid input";
    } else if(A == B) {
        cout << "Prices Equal";
    } else {
        cout << max(A, B) << " is more expensive";
    }
    return 0;
}