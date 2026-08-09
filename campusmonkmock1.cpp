/*
warehouse arrangement problem 
in a warehouse, boxes are palced in a row and each box has a number printed on it.
the current arrangement of boxes is represented by an integer array nums.
the warehouse manager wants to rearrange the boxes to create the next arrangements in dictionary order(lexicographically greater order)
if we list all possible arrangement of the boxes in sorted order, the manager wants the arrangements that comes immediately after current one.
However:
if the current arrangement is already the largest possible order, the boxes should be arranged into the smallest possible order(ascending order).
the rearrangement must be done:
Directly on the original array
using constant extra memory
Input format:
first line contains an integer n representing the size of the array.
second line contains n space separated integers representing the array elements.
output format:
print the next permutation of the array as space separated integers.
input:
3
1 2 3
output:
1 3 2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
while(i >= 0 && nums[i] >= nums[i + 1]) {
    i--;
}
if(i >= 0) {
    int j = n - 1;
    while(j >= 0 && nums[j] <= nums[i]) {
        j--;
    }
    swap(nums[i], nums[j]);
}
reverse(nums.begin() + i + 1, nums.end());
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    nextPermutation(nums);
    for(int i = 0; i < n; i++) {
        cout << nums[i] << (i == n - 1 ? "" : " ");
    }
    return 0;
}