/*
Find Second Smallest and Second Largest Element in an array
43
Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.
Examples
Example 1:
Input:
 [1, 2, 4, 7, 7, 5]  
Output:
Second Smallest : 2  
Second Largest : 5  
Explanation:
  The elements are sorted as 1, 2, 4, 5, 7, 7.  
Hence, the second smallest element is 2, and the second largest element is 5.
Example 2:
Input:
 [1]  
Output:
Second Smallest : -1  
Second Largest : -1  
Explanation:
  Since there is only one element in the array, it is both the largest and smallest element.  
Therefore, there is no second smallest or second largest element present.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int secondSmallest(vector<int>& nums) {
    int n = nums.size();
    if(n < 2) return -1;
    int small = INT_MAX, smallest = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(small > nums[i]) {
            smallest = small;
small = nums[i];
        }
        else if(nums[i] < smallest && nums[i] != small) {
            smallest = nums[i];
        }
    }
    return smallest;
}
int secondLargest(vector<int>& nums) {
    int n = nums.size();
    if(n < 2) return -1;
    int large = INT_MIN, largest = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(large < nums[i]) {
            largest = large;
            large = nums[i];
        }
        else if(nums[i] > largest && nums[i] != large) {
            largest = nums[i];
        }
    }
    return largest;
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
    cout << secondSmallest(nums) << "\n";
    cout << secondLargest(nums) << "\n";
    return 0;
}