/*
Given an integer n, return all the n digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

Examples :

Input: n = 1
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
Explanation: Single digit numbers are considered to be strictly increasing order.
Input: n = 2
Output: [12, 13, 14, 15, 16, 17, 18, 19, 23....79, 89]
Explanation: For n = 2, the correct sequence is 12 13 14 15 16 17 18 19 23 and so on up to 89.
Input: n = 15
Output: []
Explanation: No such number exist. 
Constraints:
1 ≤ n ≤ 105

Appraoch - using the generation of valid numbers directly TC:O(C(9,n)) SC:O(n)
*/
#include<iostream>
#include<vector>
using namespace std;
void generateNumbers(int remainDigit, int currDigit, int currNum, vector<int>& result) {
    if(remainDigit == 0) {
result.push_back(currNum);
return;
    }
    for(int nextDigit = currDigit + 1; nextDigit <= 9; nextDigit++) {
        generateNumbers(remainDigit - 1, nextDigit, currNum * 10 + nextDigit, result);
    }
}
vector<int>increasingNumbers(int n) {
    vector<int> result;
    if(n == 1) {
        for(int digit = 0; digit <= 9; digit++) 
            result.push_back(digit);
            return result;
    }
    if(n > 9) 
        return result;
        for(int firstDigit = 1; firstDigit <= 9; firstDigit++) {
            generateNumbers(n - 1, firstDigit, firstDigit, result);
    }
    return result;
}
int main() {
    int N;
    cin >> N;
    vector<int> ans = increasingNumbers(N);
for(int num : ans) {
    cout << num << " ";
}
return 0;
}