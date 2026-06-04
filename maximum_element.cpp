/*
You are given an array of integers, arr,
and an integer k. Your task is to find and print the maximum number in
each contiguous window of size k.
Sample test case 1:
Input:
arr = [1, 3, -1, -3, 5, 3, 6, 7] k=3
Output:
[3, 3, 5, 5, 6, 7]
approach using the sliding window and deque to find maximum element in each window of size k
TC:O(n) SC:O(k)
*/
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
int k;
cin >> k;
deque<int> dq;
vector<int> ans;
for(int i = 0; i < n; i++) {
    while(!dq.empty() && dq.front() <= i - k) {
        dq.pop_front();
    }
    while(!dq.empty() && arr[dq.back()] < arr[i]) {
        dq.pop_back();
    }
    dq.push_back(i);
    if(i >= k - 1) {
        ans.push_back(arr[dq.front()]);
    }
}
cout << "[";
for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() - 1) {
        cout << ", ";
    }
}
cout << "]";
return 0;
}