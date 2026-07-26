/*
Problem Statement: Given an array of N integers (which may include negative numbers and zeros), find and print the largest product obtainable from any contiguous non-empty subarray. 
For example — for the array [2, 3, −2, 4], the contiguous subarray [2, 3] gives the maximum product, 6. (Including −2 would flip the sign, and the 4 is isolated by the negative.) 
Requirement: Your solution must run in O(N) time. The presence of negative numbers means the standard maximum-subarray approach does not directly apply — a negative times a negative can produce a large positive, so you must track both the maximum and minimum products ending at each index. 
Constraints: 
1 ≤ N ≤ 10⁵
−10 ≤ array elements ≤ 10
Input Format: 
Line 1: An integer N (the size of the array). Line 2: N space-separated integers — the elements of the array. 
Output Format: 
Print a single integer — the maximum contiguous subarray product. 
Explanation: 
Because multiplying by a negative number swaps the roles of "largest" and "smallest", you must track both at each step: 
Initialise maxProd, minProd, and result all to the first element.
For each subsequent element x: if x is negative, swap maxProd and minProd; maxProd = max(x, maxProd × x); minProd = min(x, minProd × x); result = max(result, maxProd).
After the single pass, result holds the answer
Tracking minProd is essential: a very negative running product can become the maximum the moment it is multiplied by another negative number. Zeros naturally reset both running products via the max(x, ...) / min(x, ...) comparisons. 
Time complexity: O(N). 
Space complexity: O(1). 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxProduct(vector<int> & arr) {
    int n = arr.size();
    long long maxProd = arr[0];
    long long minProd = arr[0];
    long long result = arr[0];
    for(int i = 1; i < n; i++) {
        long long x = arr[i];
        if(x < 0) {
            swap(maxProd, minProd);
        }
        maxProd = max(x, maxProd * x);
        minProd = min(x, minProd * x);
        result = max(result, maxProd);
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxProduct(arr);
    return 0;
}