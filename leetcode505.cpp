#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int freq[26] = {0};
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        int oddCount = 0;
        int mid = -1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                oddCount++;
                mid = i;
            }
        }
        if (oddCount > 1) {
            return "";
        }
        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }
        int n = s.size();
        int half = n / 2;
        string ans(n, ' ');
        auto makePalindrome = [&]() {
            if (mid != -1) {
                ans[half] = char('a' + mid);
            }
            for (int i = 0; i < half; i++) {
                ans[n - 1 - i] = ans[i];
            }
        };
        int pos = 0;
        while (pos < half) {
            int ch = target[pos] - 'a';
            if (freq[ch] == 0) {
                break;
            }
            ans[pos] = target[pos];
            freq[ch]--;
            pos++;
        }
        if (pos == half) {
            makePalindrome();
            if (ans > target) {
                return ans;
            }
        }
        while (true) {
            if (pos < half) {
                int minChar = (target[pos] - 'a') + 1;
                for (int ch = minChar; ch < 26; ch++) {
                    if (freq[ch] != 0) {
                        ans[pos] = char('a' + ch);
                        freq[ch]--;
                        int dst = pos + 1;
                        for (int c = 0; c < 26; c++) {
                            for (int k = 0; k < freq[c]; k++) {
                                ans[dst++] = char('a' + c);
                            }
                        }
                        makePalindrome();
                        return ans;
                    }
                }
            }
            if (pos == 0) {
                return "";
            }
            pos--;
            int ch = target[pos] - 'a';
            freq[ch]++;
        }
    }
};
int main() {
    string s, target;
    cin >> s;
    cin >> target;
    Solution obj;
    string result = obj.lexPalindromicPermutation(s, target);
    cout << result << endl;
    return 0;
}