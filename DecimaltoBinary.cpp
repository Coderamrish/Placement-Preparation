/*
 Joseph is learning digital logic subject which will be for his next semester. He usually tries to solve unit assignment problems before the lecture. Today he got one tricky question. The problem statement is “A positive integer has been given as an input. Convert decimal value to binary representation. Toggle all bits of it after the most significant bit including the most significant bit. Print the positive integer value after toggling all bits”. Click here to see solution
Constrains-
1<=N<=100
Example 1:
Input :
10 -> Integer
Output :
5 -> result- Integer
Explanation:
Binary representation of 10 is 1010. After toggling the bits(1010), will get 0101 which represents “5”. Hence output will print “5”.

Approach :- convert all the decimal to binary and toogle bits after most significant bit and then convert back to decimal and print result.
TC:O(logn) SC:O(1)
*/
#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int temp = n;
    int mask = 0;
    while (temp > 0) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }
    int ans = n ^ mask;
    cout << ans;
    return 0;
}