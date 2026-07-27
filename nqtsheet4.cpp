/*
Reverse a given Array
14
Problem Statement: You are given an array. The task is to reverse the array and print it.
Examples
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.
Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
void reverseArray(vector<int>& nums) {
    int n = nums.size();
   int start = 0, end = nums.size() - 1;
   while(start < end) {
    swap(nums[start], nums[end]);
    start++;
    end--;
    // reverse(nums.begin(), nums.end());
   }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    getline(cin , n);
    stringstream ss(n);
    vector<int> nums;
    int num;
    while(ss >> num) nums.push_back(num);
    reverseArray(nums);
    for(int x : nums) cout << x << " ";
    return 0;
}