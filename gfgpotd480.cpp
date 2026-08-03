/*
Given an array arr[] of positive integers and an integer k, find the total number of pairs of elements that have an absolute difference strictly less than k.
Note:  Pair (i, j) is considered the same as (j, i).
Examples:
Input : arr[] = [1, 10, 4, 2], k = 3
Output : 2
Explanation: We have an array arr[] = [1, 10, 4, 2] and k = 3 We can make only two pairs with a difference of less than 3. (1, 2) and (4, 2). So, the answer is 2.
Input : arr[] = [2, 3, 4], k = 5
Output : 3
Explanation:  For the given array arr[] = [2, 3, 4] and k = 5, there are 3 valid pairs where the absolute difference between the pair's elements is less than 5. These pairs are (2, 3), (2, 4), and (3, 4). Hence, the output is 3.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ k ≤ 105
1 ≤ arr[i] ≤ 105
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int pairDiff(vector<int>& arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int total = 0;
    int diff = 0;
    for(int i = 0; i < n; i++) {
        while(arr[i] - arr[diff] >= k) {
            diff++;
        }
        total += (i - diff);
    }
    return total;
}
int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n, k;
cin >> n >> k;
vector<int> arr(n);
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}
cout << pairDiff(arr, k) << endl;
return 0;
}