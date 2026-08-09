/*
Problem: Count Smaller Elements Before Each Target
You are given an array a and a target value.
For every occurrence of the target, count how many elements before that occurrence are strictly smaller than the target.
Finally, return the total count.
Example
a = [50, 100, 200, 60, 100]
target = 100
Step 1: First occurrence of 100
First 100 is at index 1.
Elements before it:
[50]
Elements smaller than 100:
50
Count:
1
Step 2: Second occurrence of 100
Second 100 is at index 4.
Elements before it:
[50, 100, 200, 60]
Check against target 100:
50  → smaller 
100 → not smaller 
200 → not smaller 
60  → smaller 
Count:
2
Final answer
1 + 2 = 3
So:
Output = 3
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long targetElement(vector<int>& nums, int target) {
   int  n = nums.size();
    long long cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if(nums[i] == target) {
            ans += cnt;
        }
        if(nums[i] < target) {
            cnt++;
        }
    }
    return ans;
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
    int target;
    cin >> target;
    int result = targetElement(nums, target);
    cout << result << endl;
    return 0;
}