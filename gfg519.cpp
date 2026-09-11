/*
Given an array arr[] of integers and an integer k, find a subsequence of size k whose product is maximum among all possible subsequences of size k. Return the maximum product that can be obtained.

Examples:

Input: arr[] = [1, 2, 0, 3], k = 2
Output: 6
Explanation: Subsequence containing elements {2, 3} gives maximum product: 2*3 = 6
Input: arr[] = [1, 2, -1, -3, -6, 4], k = 4
Output: 144
Explanation: Subsequence containing {2, -3, -6, 4} gives maximum product: 2*(-3)*(-6)*4 = 144
Constraints:

arr.size() ≤ 30
-10 ≤ arr[i] ≤ 10
1 ≤ k ≤ arr.size()
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int product = 1;
        if (arr[n - 1] == 0 && (k & 1)) {
            return 0;
        }
        if (arr[n - 1] <= 0 && (k & 1)) {
            for (int i = n - 1; i >= n - k; i--) {
                product *= arr[i];
            }
            return product;
        }
        int left = 0;
        int right = n - 1;
        if (k & 1) {
            product *= arr[right];
            right--;
            k--;
        }
        k /= 2;
        for (int i = 0; i < k; i++) {
            int leftProduct = arr[left] * arr[left + 1];
            int rightProduct = arr[right] * arr[right - 1];
            if (leftProduct > rightProduct) {
                product *= leftProduct;
                left += 2;
            } else {
                product *= rightProduct;
                right -= 2;
            }
        }
        return product;
    }
};
int main() {
    Solution obj;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << obj.maxProduct(arr, k) << endl;
    return 0;
}