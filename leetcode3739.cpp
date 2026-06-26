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

1 <= nums.length <= 10​​​​​​​5
1 <= nums[i] <= 10​​​​​​​9
1 <= target <= 109

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int n;
    vector<int> tree;
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int size = nums.size();
        n = 2 * size + 1;
        tree.assign(n + 1, 0);
        long long result = 0;
        int prefix_sum = 0;
        int shift = size + 1;
        update(0 + shift, 1);
        for (int x : nums) {
            if (x == target) {
                prefix_sum += 1;
            } else {
                prefix_sum -= 1;
            }
            result += query(prefix_sum + shift - 1);
            update(prefix_sum + shift, 1);
        }
        return result;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    if (!(cin >> size)) return 0;
    vector<int> nums(size);
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    Solution solver;
    long long ans = solver.countMajoritySubarrays(nums, target);
    cout << ans << "\n";
    return 0;
}