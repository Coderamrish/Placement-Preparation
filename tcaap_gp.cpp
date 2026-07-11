/*
Given the following inputs for an arithemetic Progression (AP):
a = First Term
d = common difference
n = term number
 Print the folowing three terms:
 (n - 2)th term
 (n - 1)th term
 nth term
 Formula
 The nth term of an AP is:
 Tn = a + (n - 1) d
 Input format
 Three integers
 a d n
 where 
 a = first term
 d = common diff
 n = required term number
 output format :
 Print the 
 (n - 2)th_term (n - 1)th_term nth_term
 Example 1 :
 input:
 2 3 5
 output:
 8 11 14
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a , d , n;
    if(!(cin >> a >> d >> n)) return 0;
    int term1 = a + (n - 3) * d;
    int term2 = a + (n - 2) * d;
    int term3 = a + ( n - 1) * d;
    cout << term1 << " " << term2 << " " << term3 << "\n";
    return 0;
}