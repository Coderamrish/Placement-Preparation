/*
Find the smallest element in an array
9
Problem Statement: Given an array, we have to find the smallest element in the array.
Examples
Example 1:
Input:
 arr[] = {2, 5, 1, 3, 0}  
Output:
 0  
Explanation:
  0 is the smallest element in the array.
Example 2:
Input:
 arr[] = {8, 10, 5, 7, 9}  
Output:
 5  
Explanation:
  5 is the smallest element in the array.
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<sstream>
#include<string>
using namespace std;
 int smallestElement(vector<int> nums) {
int n = nums.size();
int mini = nums[0];
for(int i = 0; i < n; i++) {
    if(mini > nums[i]) {
        mini = nums[i];
    }
}
return mini;
 }
 int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    getline(cin, n);
    n.erase(remove(n.begin(), n.end(), '['), n.end());
    n.erase(remove(n.begin(), n.end(), ']'), n.end());
    stringstream ss(n);
    vector<int> nums;
    string token;
    while(getline(ss, token, ',')) {
        token.erase(remove(token.begin(), token.end(), ' '), token.end());
        nums.push_back(stoi(token));
    }
 cout << smallestElement(nums);
return 0;
 }