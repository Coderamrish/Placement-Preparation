/*
Problem Statement: Given an array of N integers (which may include negative numbers), find and print the maximum sum obtainable from any contiguous non-empty subarray. 
For example — for the array [−2, 1, −3, 4, −1, 2, 1, −5, 4], the contiguous subarray [4, −1, 2, 1] has the largest sum, which is 6. 
Requirement: Your solution must run in O(N) time using Kadane's algorithm. A brute-force O(N²) approach that examines every subarray will time out for the upper input size. The subarray must be non-empty, so even an all-negative array must return its single largest element. 
Constraints: 
1 ≤ N ≤ 10⁵
−10⁴ ≤ array elements ≤ 10⁴
Input Format: 
Line 1: An integer N (the size of the array). Line 2: N space-separated integers — the elements of the array. 
Output Format: 
Print a single integer — the maximum contiguous subarray sum. 
Explanation: 
Kadane's algorithm maintains two running values as it scans the array once: 
currentMax — the maximum subarray sum ending at the current index.
globalMax — the best subarray sum seen anywhere so far
Initialise both to the first element. For each subsequent element x: currentMax = max(x, currentMax + x) — either start a fresh subarray at x, or extend the previous subarray; globalMax = max(globalMax, currentMax). 
Initialising with the first element (rather than 0) correctly handles the all-negative case, since the algorithm never forces an empty subarray. After the single pass, globalMax holds the answer. 
Time complexity: O(N). 
Space complexity: O(1). 
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
 long long currentMax = arr[0];
 long long globalMax = arr[0];
 for(int i = 1; i < N; i++) {
    currentMax = max(arr[i], currentMax + arr[i]);
    globalMax = max(globalMax, currentMax);
 }
 cout << globalMax << "\n";
 return 0;
}