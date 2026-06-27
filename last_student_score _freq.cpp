/*
You are thr student ID and corresponding score of N students.
you are also given:
X-> score to check
K -> required frequency
Count how many ties the score X appears.
if the frequency of X is greater than or equal or equal to K, print the last student ID having score X.
otherwise, print -1.
Input Format
First line contains integer N.
Next N values contain:
StudentID Score
Next line contains integer X.
Last line contains integer K.
Example Input
5,
112, 13,
114, 15,
117, 15,
118, 13,
119, 20,
15,
2
Explanation
students with score 15:
114
117
Frequency of 15 = 2
Since:
2 >= 2
Return the last student ID having score 15:
117
Output
117
*/
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<string>parts;
    string temp;
    while(getline(ss,temp,',')) {
        parts.push_back(temp);
    }
    int n = stoi(parts[0]);
    vector<pair<int,int>>arr;
    for(int i = 1; i <= n; i++) {
stringstream data(parts[i]);
int id, score;
data >> id >> score;
arr.push_back({id,score});
    }
    int x = stoi(parts[n+1]);
    int k = stoi(parts[n+2]);
    int count = 0;
    int lastId = -1;
    for(auto p : arr) {
        if(p.second == x) {
            count++;
            lastId = p.first;
        }
    }
    if(count >= k) cout << lastId;
    else
    cout << -1;
    return 0;
}