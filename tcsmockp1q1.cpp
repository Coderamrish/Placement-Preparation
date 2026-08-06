/*
You are given a number N, and your task is to determine whether it is a "Good Number" or not. A Good Number is defined as a number that is divisible by the sum of its own digits. If the number is divisible by the sum of its digits, it is classified as Good, otherwise, it is classified as Bad.
Input Format
Each test case contains a single integer N, the number you need to check.
Output Format
For each test case, print "Good Number" if the number is a Good, otherwise print "Bad Number".
Constraints
1≤N≤106
Sample 1:
Input
Output
3
18
19
21
Good Number
Bad Number
Good Number
Explanation:
Test Case 1: For the first test case, the sum of digits of 18 is 1+8=9. Since 18÷9=2, 18 is a Good Number.
Test Case 2: For the second test case, the sum of digits of 19 is 1+9=10. Since 19÷10 is not an integer, 19 is a Bad Number.
Test Case 3: For the third test case, the sum of digits of 21 is 2+1=3. Since 21÷3=7, 21 is a Good Number.
*/
#include<iostream>
using namespace std;
void numberclassified(int n) {
    int temp = n;
    int sum = 0;
    while(temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    if(n % sum == 0) cout << "Good Number" << endl;
    else
     cout << "Bad Number" << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    numberclassified(n);
    return 0;
}
