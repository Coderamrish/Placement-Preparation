/*
given an array, sort it in ascending order. for each elelemnt, find the absolute difference between its original index and its index in the sorted array.
Return the sum of these differences.
EX 1:
arr = [40, 10, 30, 20]
original postitons
Element original index
40 0
10 1
30 2
20 3
sorted array = [10, 20, 30, 40]
new position
element sorted index
element sprted index
10 0
20 1
30 2
40 3
differences
10: [1 - 0] = 1
20 : [3 - 1] = 2
30 : [2 - 2] = 0
40 : [0 - 3] = 3
sum = 1 + 2 + 0 + 3 = 6
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long findSum(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({arr[i], i});
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(v[i].second - i);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findSum(arr) << endl;
    return 0;
}