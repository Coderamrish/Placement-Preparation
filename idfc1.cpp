/*
Given two integers N (number of cakes) and M (number of people), determine the minimum number of cuts required so that each person receives an equal share of the cake.

Example:

Input:
N = 2
M = 6

Output:
4
Explanation:

First cake → cut into 3 equal pieces (2 cuts).
Second cake → cut into 3 equal pieces (2 cuts).
Total cuts = 4.
Constraints:

1 <= N, M <= 1000
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
if(M % N != 0) {
    cout << -1;
} else {
    cout << M - N;
}
return 0;
}