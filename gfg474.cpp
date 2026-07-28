/*
Given an array arr[] of distinct positive numbers. Split the array into the minimum number of subsets (or subsequences) such that each subset contains consecutive numbers.
Examples:
Input: arr[] = [100, 56, 5, 6, 102, 58, 101, 57, 7, 103, 59]
Output: 3
Explanation: [5, 6, 7], [56, 57, 58, 59], [100, 101, 102, 103] are 3 subsequences in which numbers are consecutive.
Input: arr[] = [10, 100, 105]
Output: 3
Explanation: [10], [100] and [105] are 3 subset in which numbers are consecutive.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 109
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
int splitArray(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int>s(nums.begin(), nums.end());
    int cnt = 0;
    for(int x : nums) {
        if(s.find(x - 1) == s.end()) cnt++;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
vector<int> nums(n);
for (int i = 0; i < n; i++) {
    cin >> nums[i];
}
cout << splitArray(nums) << "\n";
return 0;
}