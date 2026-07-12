/*
Given a string S, print the frequency of each distinct character in the order of its first occurrence.

Input Format
A single string S.
Output Format
Print each distinct character followed by its frequency, one per line.
Sample Input
abacbdab
Sample Output
a 3
b 3
c 1
d 1
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for(char ch : s) {
        freq[ch]++;
    }
    for(char ch : s) {
        if(freq[ch] != 0){
            cout << ch << " " << freq[ch] << "\n";
            freq[ch] = 0;
        }
    }
    return 0;
}