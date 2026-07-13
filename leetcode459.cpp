/*
A sequential digit number is a number in which every digit is exactly one greater than its previous digit.

For example:

12, 23, 123, 4567, 6789

are sequential digit numbers, whereas

21, 135, 1223

are not.

Given two integers L and R, print all sequential digit numbers that lie in the range [L, R] in increasing order.

If no such number exists, print -1.

Input Format
The first line contains an integer L.
The second line contains an integer R.
Output Format

Print all sequential digit numbers between L and R (inclusive), separated by spaces.

If there are no such numbers, print -1.

Constraints
10 ≤ L ≤ R ≤ 10^9
Sample Input 1
100
500
Sample Output 1
123 234 345 456
Explanation

The sequential digit numbers between 100 and 500 are:

123
234
345
456
Sample Input 2
1000
13000
Sample Output 2
1234 2345 3456 4567 5678 6789 12345
Sample Input 3
50
80
Sample Output 3
56 67 78
Sample Input 4
900
1000
Sample Output 4
-1

Approach - there are different appropaches to solve this question
Approach 1 - using brute force Iterate through every number from low to high.
For each number, convert it to a string.
Check if each adjacent pair of digits differs by exactly 1.
If all adjacent pairs satisfy this condition, add the number to the result.
Return the result list.
TC:O(n) SC: O(1)

Approaxh 2 : - 
Determine the digit lengths to consider: from the number of digits in low to that of high.
For each digit length d:
For each starting digit s from 1 to 9:
If s + d > 10, break (not enough consecutive digits available).
Build the number by starting with s and appending s+1, s+2, etc.
If the result is within [low, high], add it to the result.
Return the result list.
TC:O(1) SC:O(1)

Approach 3 - Initialize a queue with digits 1 through 9.
While the queue is not empty:
Dequeue a number n.
If n > high, skip it.
If n is within [low, high], add it to the result.
Get the last digit of n. If it's less than 9, enqueue n * 10 + (lastDigit + 1).
Return the result list.
TC:O(1) SC:O(1)

Approach 4 : 
 Define a DFS function that takes the current number:
If the number exceeds high, return.
If the number is within [low, high], add it to the result.
If the last digit is less than 9, recurse with num * 10 + (lastDigit + 1).
Call DFS starting from each digit 1 through 9.
Sort the result list and return it.
TC:O(1) SC:O(1)
Approach 5 - 
Define the string nums = "123456789".
For each window size d from 2 to 9:
Slide the window across nums:
Extract the substring of length d starting at index i.
Convert it to an integer.
If it exceeds high, break the inner loop.
If it is within [low, high], add it to the result.
Return the result list.
TC:O(1) SC:O(1)
*/
// Apprach 3 using BFS 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
    int low, high;
    cin >> low >> high;
    vector<int> res;
    queue<int> q;
    for(int i = 1; i < 10; i++) {
        q.push(i);
    }
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        if(n > high) {
            continue;
        }
        if(n >= low && n <= high) {
            res.push_back(n);
        }
        int ones = n % 10;
        if(ones < 9) {
            q.push(n * 10 + (ones + 1));
        }
    }
    if(res.empty()) {
        cout << -1;
    } else {
        for(int x : res) {
            cout << x << " ";
        }
    }
    return 0;
}