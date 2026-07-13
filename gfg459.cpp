/*
Problem Statement

A number X is processed with each element of an array from left to right.

For every array element arr[i], update X using the following rules:

If X > arr[i], then

X = X + (X - arr[i])

Otherwise,

X = X - (arr[i] - X)

Your task is to find the smallest initial value of X such that X never becomes negative during the entire process.

Input Format
The first line contains an integer N, representing the size of the array.
The second line contains N space-separated integers representing the array elements.
Output Format

Print the minimum initial value of X such that it never becomes negative while processing the array.

Constraints
1 ≤ N ≤ 10^6
1 ≤ arr[i] ≤ 10^4
Sample Input 1
5
3 4 3 2 4
Sample Output 1
4
Explanation

Start with X = 4

After 3 : X = 5
After 4 : X = 6
After 3 : X = 9
After 2 : X = 16
After 4 : X = 28

X never becomes negative.

Sample Input 2
2
4 4
Sample Output 2
3
Explanation

Start with X = 3

After 4 : X = 2
After 4 : X = 0

X remains non-negative throughout the process.
Approach - using the greedy method reverse tc : O(n) SC:(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    if(!(cin >> N)) return 0;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
ans = (ans + arr[i] + 1) / 2;
    }
    cout << ans;
    return 0;
}