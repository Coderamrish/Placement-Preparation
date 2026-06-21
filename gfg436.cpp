/*
Given a string s of lowercase English letters, you can swap all occurrences of any two distinct characters at most once. Return the lexicographically smallest string after this operation.
Examples:

Input: s = "ccad"
Output: "aacd"
Explanation: In ccad, we choose a and c and after doing the replacement operation once, we get aacd and this is the lexicographically smallest string possible. 
Input: s = "abba"
Output: "abba"
Explanation: In abba, we can get baab after doing the replacement operation once for a and b but that is not lexicographically smaller than abba. So, the answer is abba. 
Constraints:
1 ≤ |s| ≤ 105
approach 1 - using the try all possible method to swap each TC:O(n ^3) SC:O(n)
approach 2 - using the greedy algo with the character mapping TC:O(n) SC:O(1)
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string chooseSwap(string s) {
    int n = s.size();
    vector<int>first(26, -1);
    for(int i = 0; i < n; i++) {
        int ch = s[i] - 'a';
        if(first[ch] == -1) {
            first[ch] = i;
        }
    }
    char x = 0, y = 0;
    int pos = -1;
    for(int i = 0; i < n; i++) {
        int curr = s[i] - 'a';
        for(int c = 0; c < curr; c++) {
            if(first[c] > i){
pos= i;
x = s[i];
y = char('a' + c);
break;
            }
            }
            if(pos != -1) break;
        }
        if(pos == -1) return s;
        for(char & ch: s) {
            if(ch == x) ch = y;
else if(ch == y) ch = x;
        }
        return s;
    }
int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin >> T;
while(T--) {
    string s;
    cin >> s;
    cout << chooseSwap(s) << "\n";
}
return 0;
}
