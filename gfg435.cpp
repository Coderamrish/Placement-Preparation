/*
Given two integers a and b in the form of strings. Return the last digit of ab.

Examples:

Input: a = "3", b = "10"
Output: 9
Explanation: 310 = 59049. Last digit is 9.
Input: a = "6", b = "2"
Output: 6
Explanation: 62 = 36. Last digit is 6.
Constraints:
1 ≤ a.size(), b.size() ≤ 1000
a and b consist only of numeric digits ('0' - '9')
a and b do not contain any leading zeros, except when number itself is "0"
 approach 1 - using the Using Cyclicity of Last Digit (Mod 10) - O(n) Time O(1) Space
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    if (b == "0") {
        cout << 1;
        return 0;
    }
    int lastA = a.back() - '0';
    vector<vector<int>> cycles = {
        {0},        
        {1},        
        {2,4,8,6},  
        {3,9,7,1},  
        {4,6},      
        {5},        
        {6},        
        {7,9,3,1},  
        {8,4,2,6},  
        {9,1}       
    };
    vector<int>& cycle = cycles[lastA];
    int cycleLen = cycle.size();
    int mod = 0;
    for (char c : b) {
        mod = (mod * 10 + (c - '0')) % cycleLen;
    }
    int result = cycle[(mod == 0) ? cycleLen - 1 : mod - 1];
    cout << result;
    return 0;
}