/*
You are given an integer array nums and an integer target.

Return the number of subarrays of nums in which target is the majority element.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

 

Example 1:

Input: nums = [1,2,2,3], target = 2

Output: 5

Explanation:

Valid subarrays with target = 2 as the majority element:

nums[1..1] = [2]
nums[2..2] = [2]
nums[1..2] = [2,2]
nums[0..2] = [1,2,2]
nums[1..3] = [2,2,3]
So there are 5 such subarrays.

Example 2:

Input: nums = [1,1,1,1], target = 1

Output: 10

Explanation:

​​​​​​​All 10 subarrays have 1 as the majority element.

Example 3:

Input: nums = [1,2,3], target = 4

Output: 0

Explanation:

target = 4 does not appear in nums at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.

 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 10​​​​​​​9
1 <= target <= 109
Leetcode - 3737 count the suarrays with the majority count 2
approach - Since we only care about whether the target is the majority element, we can treat every occurrence of target as $+1$ and any other element as $-1$. A subarray will have target as its majority element if and only if the sum of this transformed subarray is strictly greater than 0.The Approach: Prefix Sums + Fenwick Tree (Binary Indexed Tree)If we compute the prefix sums of this transformed array, the sum of a subarray from index $i$ to $j$ is given by $P[j] - P[i-1]$. We want:$$P[j] - P[i-1] > 0 \implies P[j] > P[i-1]$$This reduces the problem to counting the number of pairs $(i, j)$ with $i-1 < j$ such that $P[i-1] < P[j]$. This is a classic inversion-like counting problem that can be efficiently solved using a Fenwick Tree (Binary Indexed Tree) or Segment Tree.Because the prefix sums can be negative and the array size $N \le 1000$ (though this approach easily scales to $O(N \log N)$ or even $O(N)$), we can offset the prefix sums to ensure they are strictly positive indices for our Fenwick tree. The minimum possible prefix sum is $-N$ and the maximum is $N$, so adding an offset of $N + 1$ works perfectly.
*/
#include<iostream>
#include<vector>
using namespace std;
void update(vector<int>& bit, int idx, int val, int size) {
    for (; idx < size; idx += idx & -idx) {
        bit[idx] += val;
    }
}
int query(vector<int>& bit, int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    if (!(cin >> n >> target)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int offset = n + 1;
    int bit_size = 2 * n + 2;
    vector<int> bit(bit_size, 0);
    long long count = 0;
    int current_prefix = 0;
    update(bit, 0 + offset, 1, bit_size);
    for (int i = 0; i < n; i++) {
        current_prefix += (nums[i] == target ? 1 : -1);
        count += query(bit, current_prefix + offset - 1);
        update(bit, current_prefix + offset, 1, bit_size);
    }
    cout << count << "\n";
    return 0;
}