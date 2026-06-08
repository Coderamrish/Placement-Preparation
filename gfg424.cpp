/*
Given an integer k representing the number of people to be seated and an array seats[], where 0 denotes an empty seat and 1 denotes an occupied seat.

Determine whether it is possible to seat all k people such that no two occupied seats are adjacent (including newly seated people).

Examples:

Input: k = 2, seats[] = [0, 0, 1, 0, 0, 0, 1]
Output: true
Explanation: The two people can sit at index 0 and 4.
Input: k = 1, seats[] = [0, 1, 0]
Output: false
Explanation: There is no way to get a seat for one person.
Constraints:
0 ≤ k ≤ 105
1 ≤ seats.size() ≤ 105
seats[i] == 0 or seats[i] == 1,
Approach 1: using greedy approach TC:O(n) SC:O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> seatsArrangement(int k, vector<int> seats) {
    int n = seats.size();
    for (int i = 0; i < n && k > 0; i++) {
        if (seats[i] == 0) {
            if ((i == 0 || seats[i - 1] == 0) &&
                (i == n - 1 || seats[i + 1] == 0)) {
                seats[i] = 1;
                k--;
            }
        }
    }
    return seats;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> seats(n);
    for (int i = 0; i < n; i++) {
        cin >> seats[i];
    }
    vector<int> result = seatsArrangement(k, seats);
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << " ";
    }
    return 0;
}