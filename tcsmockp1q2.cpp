/*
You are given two strings, str1 and str2. Your mission is to calculate the total number of occurrences of each unique character of str2 within the string str1. The task is to find the sum of occurrences of all unique characters from str2 in str1 and return this total count.
Input Format
For each test case:
The first line contains the string str1.
The second line contains the string str2.
Output Format
For each test case, output the total sum of occurrences of characters in str2 found in str1 on a new line.
Constraints
1≤T≤100
1≤∣str1∣,∣str2∣≤10
The strings consists of lowercase letters only.
Sample 1:
helloworld do
abacabadabacaba abcd
abc abcdabcdabcdabcd
3
15
3
Explanation:
Test Case 1: the character 'd' appears once and 'o' appears twice in "helloworld", so the total count is 3.
Test Case 2: The characters from "abcd" appear as follows in "abacabadabacaba": 'a': 7 occurrences 'b': 4 occurrences 'c': 2 occurrences 'd': 2 occurrences Total = 7 + 4 + 2 + 2 = 15.
Test Case 3: The characters appear only once in abc as we are calculating the unique characters of abcdabcdabcdabcd.
*/
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int countoccurence(string str1, string str2) {
    vector<int> freq(26, 0);
    vector<bool> visited(26, false);
    for(char c : str1) {
        freq[c - 'a']++;
    }
    int ans = 0;
    for(char c : str2) {
        if(!visited[c - 'a']) {
              ans += freq[c - 'a'];
           visited[c - 'a'] = true;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2;
    while(cin >> str1 >> str2) {
        cout << countoccurence(str1, str2) << endl;
    }
    return 0;
}