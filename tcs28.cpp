/*
Given an integer N, generate the first N terms of a series where:

First term = 5
Second term = 6
Every subsequent term is the sum of the previous two terms.
Input Format
First line contains an integer N.
Output Format
Print the first N terms of the series separated by spaces.
Sample Input 1
6
Sample Output 1
5 6 11 17 28 45
*/
#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    long long a = 5, b = 6;
    if(N >= 1) 
        cout << a;
    if(N >= 2)
    cout <<" "<< b;
    for(int i = 3; i <= N; i++) {
        long long c = a + b;
        cout << " " << c;
        a = b;
        b = c;
    }
    cout << "\n";
    return 0;
}