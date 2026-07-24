/*
You are given an integer array nums.

A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

Return the number of unique XOR triplet values from all possible triplets (i, j, k).

 

Example 1:

Input: nums = [1,3]

Output: 2

Explanation:

The possible XOR triplet values are:

(0, 0, 0) → 1 XOR 1 XOR 1 = 1
(0, 0, 1) → 1 XOR 1 XOR 3 = 3
(0, 1, 1) → 1 XOR 3 XOR 3 = 1
(1, 1, 1) → 3 XOR 3 XOR 3 = 3
The unique XOR values are {1, 3}. Thus, the output is 2.

Example 2:

Input: nums = [6,7,8,9]

Output: 4

Explanation:

The possible XOR triplet values are {6, 7, 8, 9}. Thus, the output is 4.

 

Constraints:

1 <= nums.length <= 1500
1 <= nums[i] <= 1500
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<bitset>
using namespace std;
int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return 1;
    unordered_set<int>pairs;
    bitset<2048> triplets;
for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        pairs.insert(nums[i] ^ nums[j]);
    }
}
for(int x : pairs) {
    for(int num : nums) {
        triplets.set(x ^ num);
    }
}
return triplets.count();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n));
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << uniqueXorTriplets(nums);
    return 0;
}
