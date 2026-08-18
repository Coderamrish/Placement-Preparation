/*
Given an array arr[]  and a range from l to r, the task is to count the number of triplets having a sum in the range [l, r].

Examples :

Input: arr = [8, 3, 5, 2], l = 7, r = 11
Output: 1
Explanation: There is only one triplet [2, 3, 5] having sum 10 in range [7, 11].
Input: arr = [5, 1, 4, 3, 2], l = 2, r = 7
Output: 2
Explanation: There are two triplets having sum in range, [1,4,2] and [1,3,2].
Constraints:
1 ≤ arr.size≤ 103
1 ≤ arr[i] ≤ 103
1 ≤ l ≤ r ≤ 109
*/
// C++ program to count triplets with
// sum that lies in given range [a, b].
#include <bits/stdc++.h>
using namespace std;
int countTripletsLessThan(vector<int> &arr, int val)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int ans = 0;
    int j, k;
    int sum;
    for (int i = 0; i < n - 2; i++) {
        j = i + 1;
        k = n - 1;
        while (j < k) {
            sum = arr[i] + arr[j] + arr[k];
            if (sum > val)
                k--;
            else {
                ans += (k - j);
                j++;
            }
        }
    }
    return ans;
}
int countTriplets(vector<int> &arr, int l, int r)
{
    int res;
    res = countTripletsLessThan(arr, r) -
        countTripletsLessThan(arr, l - 1);
    return res;
}
int main()
{
    vector<int> arr = { 2, 7, 5, 3, 8, 4, 1, 9 };
    int l = 8, r = 16;
    cout << countTriplets(arr, l, r) << endl;
    return 0;
}