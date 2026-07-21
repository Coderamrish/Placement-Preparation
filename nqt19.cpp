/*
Given an array of integers, replace each element with its position (rank) in the sorted list of unique elements.
The smallest unique element has rank 1, the next smallest has rank 2, and so on , if an elelemnt appears more than once, assign the same rank to each occurence . example
Input:
23 6 4 6 1
output:
4 3 2 3 1
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n)) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for(int i = 0; i < n; i++) {
        int rank = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
        cout << rank << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}
