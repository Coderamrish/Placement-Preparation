/*
Count frequency of each element in the array
24
Problem Statement: Given an array, we have found the number of occurrences of each element in the array.
Examples
Example 1:
Input: arr[] = {10,5,10,15,10,5};
Output: 10  3
	            5  2
                15  1
Explanation: 10 occurs 3 times in the array
	      5 occurs 2 times in the array
              15 occurs 1 time in the array
Example2: 
Input: arr[] = {2,2,3,4,4,2};
Output: 2  3
	           3  1
               4  2
Explanation: 2 occurs 3 times in the array
	     3 occurs 1 time in the array
             4 occurs 2 time in the array     
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<sstream>
using namespace std;
void freqCnt(vector<int> nums){
int n = nums.size();
unordered_map<int, int>freq;
for(int x : nums) {
    freq[x]++;
}
for(auto it : freq) {
cout << it.first << " " << it.second << "\n";
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
freqCnt(nums);
return 0;
}