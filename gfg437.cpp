/*
Given an integer array height[], where height[i] represents the height of the ith bar arranged in a row, find the maximum rectangular area that can be formed by selecting any two bars. The area is calculated based on the original positions of the selected bars.

Examples :

Input: height[] = [2, 5, 4, 3, 7]
Output: 10
Explanation:

The maximum rectangular area is formed by selecting the bars of heights 5 and 7.
There are 2 bars between them, so the area is: min(5, 7) × 2 = 10
Input: height[] = [1, 3, 4]
Output: 1
Explanation: Selecting bars 1 and 4 gives one bar between them, so the area is: min(1, 4) × 1 = 1
Constraints:
1 ≤ height.size() ≤ 105
1 ≤ height[i] ≤ 104
approach 1 - using the brute force method where try all possible method TC:O(n^2) SC:O(1)
approach 2 - using the sorting tc :O(n log n) SC:O(n)
Approach 3 - using the two pointers algorithm TC:O(n) SC:O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxHeightBars(vector<int>& height) {
    int n = height.size();
    int res = 0;
    int i = 0, j = height.size() - 1;
    while(j > i) {
        int width = j - i - 1;
        if(height[i] < height[j]) {
            res = max(res, width * height[i]);
            i++;
        } else if(height[i] > height[j]) {
            res = max(res, width * height[j]);
            j--;
        } else {
            res = max(res, width * height[i]);
            i++;
            j--;
        }
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int>height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }
    int result = maxHeightBars(height);
    cout << result;
    return 0;
}