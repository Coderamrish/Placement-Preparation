/*
Given a sorted array print all the indices of the given target element
input:
one sorted array and target element
output:
the indices at which the target element is present.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    if(!(cin >> N)) return 0;
    vector<long long> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    long long target;
    cin >> target;
    auto first = lower_bound(arr.begin(), arr.end(), target);
    if(first == arr.end() || *first != target) {
        cout << -1;
        return 0;
    }
    auto last = upper_bound(arr.begin(), arr.end(), target);
    int start_idx = distance(arr.begin(), first);
    int end_idx = distance(arr.begin(), last);
    for(int i = start_idx; i < end_idx; i++) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}