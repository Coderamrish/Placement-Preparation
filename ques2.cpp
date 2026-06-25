/*
2.	Given two non-negative integers n1 and n2, count how many numbers in the range [n1, n2] do not have repeated digits.
Input Format:
•	Two integers: n1 n2
Output Format:
•	Single integer: count of numbers without repeated digits
Sample Input  1
11
15
Output
4
Sample Input 2
10
13
Output
3
Approach - For every number in range [n1, n2]:

Check if all digits are unique
Use a frequency array (0–9) to detect repetition
TC:O((n2 − n1) × digits) SC:O(1)
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool hashunique(int num) {
    vector<int>freq(10, 0);
    if(num == 0) return true;
    while(num > 0) {
        int digit = num % 10;
        if(freq[digit] > 0) return false;
        freq[digit]++;
        num /= 10;
    }
    return true;
}
int main() {
    int n1 , n2;
    cin >> n1 >> n2;
    int cnt = 0;
    for(int i = n1; i <= n2; i++) {
        if(hashunique(i)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}