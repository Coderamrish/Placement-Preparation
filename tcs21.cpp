/*
Given a square matrix of size N * N, calculate its trace.
the trace of a matrix is the sum of its principal diagonal elements.
Trace = M[0][0] + M[1][1] + M[2][2]+....+M[N- 1][N - 1]
Input Format:
First line contains integer N.
Next N line contains N integer each.
output format:
Print the trace of matrix
Sample Input:
3
1 2 3
2 5 6
7 8 9
Sample output:
15
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long trace = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           int val;
cin >> val;
if(i == j)
trace += val;
        }
    }
    cout << trace << "\n";
    return 0;
}
