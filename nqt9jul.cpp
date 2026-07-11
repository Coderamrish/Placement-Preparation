/*
Given an array return the first unique element using Hashmap
Input- 
Array with Exactly one element occuring only once and other 2 times.
N size of the array
Output:
array element which appears only once but also first itme in the array.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int N;
if(!(cin >> N)) return 0;
vector<long long> arr(N);
unordered_map<long long, int> freq;
for(int i = 0; i < N; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
}
for(int i = 0; i < N; i++) {
    if(freq[arr[i]] == 1) {
        cout << arr[i] << "\n";
        return 0;
    }
}
return 0;
}

// 2nd method without using hashmap tc:o(n) SC:O(1)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    if(!(cin >> N)) return 0;
    long long unique_element = 0;
    long long curr_val;
    for(int i = 0; i < N; i++) {
        cin >> curr_val;
        unique_element ^= curr_val;
    }
    cout << unique_element << "\n";
    return 0;
}