/*
You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.
The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].
Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.
Example 1:
Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation: 
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc". 
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].
Example 2:
Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
Output: [2,3]
Explanation:
- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].
Constraints:
1 <= s.length <= 105
s consists of lowercase English letters.
k == queryCharacters.length == queryIndices.length
1 <= k <= 105
queryCharacters consists of lowercase English letters.
0 <= queryIndices[i] < s.length
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct Node {
    char leftChar;
    char rightChar;
    int prefix;
    int suffix;
    int best;
    int len;
    Node() {
        leftChar = '#';
        rightChar = '#';
        prefix = 0;
        suffix = 0;
        best = 0;
        len = 0;
    }
};
vector<Node> tree;
string s;
Node mergeNode(Node a, Node b) {
    if (a.len == 0)
        return b;
    if (b.len == 0)
        return a;
    Node res;
    res.len = a.len + b.len;
    res.leftChar = a.leftChar;
    res.rightChar = b.rightChar;
    res.prefix = a.prefix;
    if (a.prefix == a.len && a.rightChar == b.leftChar) {
        res.prefix = a.len + b.prefix;
    }
    res.suffix = b.suffix;
    if (b.suffix == b.len && a.rightChar == b.leftChar) {
        res.suffix = b.len + a.suffix;
    }
    res.best = max(a.best, b.best);
    if (a.rightChar == b.leftChar) {
        res.best = max(res.best, a.suffix + b.prefix);
    }
    return res;
}
void build(int node, int l, int r) {
    if (l == r) {
        tree[node].leftChar = s[l];
        tree[node].rightChar = s[l];
        tree[node].prefix = 1;
        tree[node].suffix = 1;
        tree[node].best = 1;
        tree[node].len = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = mergeNode(tree[2 * node],
                           tree[2 * node + 1]);
}
void update(int node, int l, int r, int pos, char ch) {
    if (l == r) {
        tree[node].leftChar = ch;
        tree[node].rightChar = ch;
        tree[node].prefix = 1;
        tree[node].suffix = 1;
        tree[node].best = 1;
        tree[node].len = 1;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * node, l, mid, pos, ch);
    }
    else {
        update(2 * node + 1, mid + 1, r, pos, ch);
    }
    tree[node] = mergeNode(tree[2 * node],
                           tree[2 * node + 1]);
}
int main() {
    cin >> s;
    int q;
    cin >> q;
    string queryCharacters;
    cin >> queryCharacters;
    vector<int> queryIndices(q);
    for (int i = 0; i < q; i++) {
        cin >> queryIndices[i];
    }
    int n = s.length();
    tree.resize(4 * n + 5);
    build(1, 0, n - 1);
    vector<int> answer;
    for (int i = 0; i < q; i++) {
        int pos = queryIndices[i];
        char ch = queryCharacters[i];
        update(1, 0, n - 1, pos, ch);
        answer.push_back(tree[1].best);
    }
    for (int x : answer) {
        cout << x << " ";
    }
    return 0;
}