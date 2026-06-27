/*
Given an array of match scores and an integer K, find the scores with the highest frequencies. print the scores  arranged in descending order of frequency and return only the first K scores. 
if two scores have the same frequency , the score that appears first in array should come first.
input format:
first line contains the element separated by commas.
second line contains integer K.
output format:
print the top K most frequent scores.
Example:
input:
7,38,17,38,3,12,4,38
2
Explanation 
frequency of each score:
38-3 times
17-2 times
3 - 1 time
12 - 1 time
4 - 1 time
Scores arranged by decreasing frequency:
38 17 3 12 4
Top K = 2 Scores are 
38 17
output:
38 17
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<sstream>
using namespace std;
int main() {
    string input;
    getline(cin, input);
    int K;
    cin >> K;
    vector<int>arr;
    stringstream ss(input);
    string temp;
    while(getline(ss, temp, ',')) {
        arr.push_back(stoi(temp));
    }
    unordered_map<int, int>freq;
    for(int num : arr) {
        freq[num]++;
    }
    vector<pair<int,int>>v;
    for(auto it : freq) {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    for(int i = 0; i < K && i < v.size(); i++) {
        cout << v[i].second << " ";
    }
    return 0;
}