/*
Find the Largest element in an array
95
Problem Statement: Given an array, we have to find the largest element in the array.
Examples
Example 1:
Input:
 arr[] = {2, 5, 1, 3, 0}  
Output:
 5  
Explanation:
5 is the largest element in the array.
Example 2:
Input:
 arr[] = {8, 10, 5, 7, 9}  
Output:
 10  
Explanation:
10 is the largest element in the array.
*/
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<string>
#include<climits>
using namespace std;
int largestElement(vector<int>& nums) {
    int n = nums.size();
    int lar = INT_MIN;
    for(int i = 0; i <  n; i++) {
        if(lar < nums[i]) {
            lar = nums[i];
        }
    }
    return lar;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    getline(cin, n);
    stringstream ss(n);
    vector<int> nums;
int num;
while(ss >> num) nums.push_back(num);
cout << largestElement(nums);
return 0;
}