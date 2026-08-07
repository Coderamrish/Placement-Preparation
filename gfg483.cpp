/*
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Examples :

Input: n = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.
Input: n = 2
Output: 2
Explanation:
{1} , {2} : All single.
{1,2} : 1 and 2 are paired.
Input: n = 1
Output: 1
Constraints:
1 ≤ n ≤ 18
*/
#include<iostream>
#include<vector>
using namespace std;
int countFriends(int n) {
    int a = 1, b=  2, c = 0;
    if(n <= 2) {
        return n;
    }
for(int i = 3; i <= n; i++) {
    c = b + (i - 1) * a;
    a = b;
    b = c;
}
return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << countFriends(n) << endl;
    return 0;
}