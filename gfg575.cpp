/*
Given an array of strings arr[]. The array represents first names of users, generate a unique username for each entry in the order it appears.
Initially, consider all usernames present in the input array as reserved.
If a username has not already been assigned to any previous user, keep it unchanged.
Otherwise, append the smallest positive integer suffix that produces a username that has not been reserved or assigned to any previous user.
Return the array of generated usernames.
Examples:
Input: arr[] = ["aba", "ab", "aba", "aba", "ab"]
Output: ["aba", "ab", "aba1", "aba2", "ab1"]
Explanation: The first occurrences of "aba" and "ab" are new, so they remain unchanged. The next "aba" is already used, so "aba1" is assigned. When "aba" appears again, "aba1" is already used, so "aba2" is assigned. Similarly, the second occurrence of "ab" becomes "ab1".
Input: arr[] = ["a", "a", "a1", "a"]
Output: ["a", "a2", "a1", "a3"]
Explanation: Initially, "a" and "a1" are reserved. The first occurrence of "a" retains its name. For the second occurrence, "a1" is already reserved, so the smallest available username is "a2". The original "a1" retains its name when processed. Finally, the last occurrence of "a" gets "a3".
Input: arr[] = ["aba1", "aba", "aba"]
Output: ["aba1", "aba", "aba2"]
Explanation: Initially, "aba1" and "aba" are reserved. The first occurrence of each retains its original name. For the second occurrence of "aba", "aba1" is already reserved, so "aba2" is assigned.
Constraints:
1 ≤ |arr| ≤ 103
1 ≤ |arr[i]| ≤ 102
arr consists of English alphabets and digits
*/
#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode *children[36];
    bool isEnd;
    int lastSuffix;
    TrieNode()
    {
        isEnd = false;
        lastSuffix = 1;
        for (int i = 0; i < 36; i++)
        {
            children[i] = nullptr;
        }
    }
};
int getCharIndex(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    return 26 + (c - '0');
}
void insert(TrieNode *root, const string &s)
{
    TrieNode *curr = root;
    for (char c : s)
    {
        int idx = getCharIndex(c);
        if (curr->children[idx] == nullptr)
        {
            curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
    }
    curr->isEnd = true;
}
TrieNode *search(TrieNode *root, const string &s)
{
    TrieNode *curr = root;
    for (char c : s)
    {
        int idx = getCharIndex(c);
        if (curr->children[idx] == nullptr)
        {
            return nullptr;
        }
        curr = curr->children[idx];
    }
    return curr->isEnd ? curr : nullptr;
}
vector<string> generateUsernames(vector<string> &arr)
{
    TrieNode *root = new TrieNode();
    vector<string> result;
    unordered_set<string> processed;
    for (const string &name : arr)
    {
        insert(root, name);
    }
    for (const string &name : arr)
    {
        if (processed.find(name) == processed.end())
        {
            processed.insert(name);
            result.push_back(name);
        }
        else
        {
            TrieNode *node = search(root, name);
            int suffix = node->lastSuffix;
            string candidate = name + to_string(suffix);
            while (search(root, candidate) != nullptr)
            {
                suffix++;
                candidate = name + to_string(suffix);
            }
            insert(root, candidate);
            result.push_back(candidate);
            node->lastSuffix = suffix + 1;
        }
    }
    return result;
}
int main()
{
    vector<string> arr = {"aba", "ab", "aba", "aba", "ab"};
    vector<string> res = generateUsernames(arr);
    for (int i = 0; i < (int)res.size(); i++)
    {
        cout << res[i];
        if (i < (int)res.size() - 1)
        {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}