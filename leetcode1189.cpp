/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.
approach using the freq cnt of the char and hashmap TC:O(n) SC:O(1)
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int maxBalloons(string text) {
    int letterCount[26] = {0};
    for(char c : text) {
        letterCount[c - 'a']++;
    }
    letterCount['l' - 'a'] /= 2;
    letterCount['o' - 'a'] /= 2;
    int result = INT_MAX;
string BalloonLetters = "balon";
for(char c : BalloonLetters) {
    result = min(result, letterCount[c - 'a']);
}
return result;
}
int main() {
    string text;
    cin >> text;
    int ans = maxBalloons(text);
    cout << ans;
    return 0;
}