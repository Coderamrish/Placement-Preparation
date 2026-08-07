/*
you are given two binary numbers as strings, your task is to compute their sum and print the resulting binary number.
the input binary numbers do not contain leading zeros unless the number itself is 0.
input format:
the first line contains a binary string A
the second line contains a binary string B
output format:
print a single binary string repersenting the sum of A and B.
constraints:
1 <= |A|, |B| <= 10^5
A and B contain only the characters '0
 and '1'
Sample input 1:
1010
1011
sample output 1:
10101
Explanation:
1010 of base2 = 10 of base10
1011 of base 2 = 11 of base10
10 + 11 = 21
21 of base 10 = 10101 of base2
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string addBinary(string A, string B) {
    int i = A.size() - 1, j = B.size() - 1;
    int carry = 0;
    string ans = "";
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += A[i] - '0';
            i--;
        }
        if(j >= 0) {
            sum += B[j] - '0';
            j--;
        }
        ans.push_back((sum % 2) + '0');
        carry = sum/ 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    string A, B;
    cin >> A >> B;
    cout << addBinary(A, B) << endl;
    return 0;
}