/*
Given an unsorted array of N integers, find the smallest missing
positive integer.

Your algorithm should run in O(N) time and use O(1) extra space.

Input Format:
First line contains an integer N.
Second line contains N space-separated integers.

Output Format:
Print the smallest missing positive integer.

Constraints:
1 <= N <= 10^5
-2^31 <= arr[i] <= 2^31 - 1

Sample Input 1:
5
1 2 0 4 5

Sample Output 1:
3

Explanation:
The positive integers 1 and 2 are present.
The smallest missing positive integer is 3.

--------------------------------------------------

Sample Input 2:
4
3 4 -1 1

Sample Output 2:
2

Explanation:
The positive integers 1, 3, and 4 are present.
The smallest missing positive integer is 2.

--------------------------------------------------

Sample Input 3:
3
7 8 9

Sample Output 3:
1

Explanation:
The array does not contain 1.
Hence, the smallest missing positive integer is 1.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(nums[i] != i + 1)
        return i + 1;
    }
    return n + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n)) return 0;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << firstMissingPositive(nums);
    return 0;
}