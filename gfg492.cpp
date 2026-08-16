/*
Given an integer array arr[], find the minimum possible product that can be obtained by multiplying the elements of any non-empty subset of the array.

Examples:

Input: arr[] = [1, 2, 3]
Output: 1
Explanation: The possible subset products are 1, 2, 3, 2, 3, 6, and 6. The minimum product is 1, obtained by selecting the subset [1].
Input: arr[] = [4, -2, 5]
Output: -40
Explanation: The minimum product is -40, obtained by selecting the subset [4, -2, 5].

Constraints:

1 ≤ arr.size() ≤ 10
-10 ≤ arr[i] ≤ 10
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int neg = 0;
    int zero = 0;
    long long prod = 1;
    int minNegAbs = INT_MAX;
    int minPos = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (x == 0)
        {
            zero++;
        }
        else
        {
            prod *= x;

            if (x < 0)
            {
                neg++;
                minNegAbs = min(minNegAbs, abs(x));
            }
            else
            {
                minPos = min(minPos, x);
            }
        }
    }
    long long ans;
    if (neg > 0)
    {
        if (neg % 2 == 1)
        {
            ans = prod;
        }
        else
        {
            ans = prod / (-minNegAbs);
        }
    }
    else
    {
        if (zero > 0)
        {
            ans = 0;
        }
        else
        {
            ans = minPos;
        }
    }
    cout << ans << endl;
    return 0;
}