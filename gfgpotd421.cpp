/*
Given two integers n and m representing the dimensions of a chessboard, find the number of ways to place one black knight and one white knight on the chessboard such that they cannot attack each other.

Note:

The knights have to be placed on different squares.
A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped).
The knights attack each other if one can reach the other in one move.
Examples:

Input: n = 2, m = 2
Output: 12 
Explanation: There are 12 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
Input: n = 2, m = 3
Output: 26
Explanation: There are 26 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
Constraints:
1 ≤ n ≤ 200
1 ≤ m ≤ 225

Approach 1 - using the count valid knight moves TC:O(n * m) SC:O(1)
Approach 2 - using formula TC:O(n * m) SC:O(1)
*/
#include<iostream>
using namespace std;
int knightMoves(int n, int m) {
    int ans = (n * m - 1) * n * m;
    if(n >= 1 && m >= 2)
    ans -= (4 * (n - 1) * (m - 2));
    if(n >= 2 && m >= 1) {
        ans -= (4 * (n - 2) * (m - 1));
    } 
    return ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    cout << knightMoves(n, m) << endl;
    return 0;
}