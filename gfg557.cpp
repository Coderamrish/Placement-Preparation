/*
Given an array arr[], you are allowed to swap two adjacent elements, arr[i] and arr[i + 1] only if their sum is even. Find the lexicographically largest array that can be obtained by performing this operation any number of times, including zero times. 
Note: An array X is lexicographically larger than another array Y if, at the first position where they differ, X has the larger element.
Examples:
Input: arr[] = [1, 3, 5]
Output: [5, 3, 1]
Explanation: We can swap any adjacent pair as all have even sum. All possible obtainable arrays are [1, 3, 5], [1, 5, 3], [3, 1, 5], [3, 5, 1], [5, 1, 3] and [5, 3, 1] The array [5, 3, 1] is lexicographically largest.
Input: arr[] = [1, 3, 4, 2]
Output: [3, 1, 4, 2]
Explanation: [1, 3, 4, 2], [1, 3, 2, 4], [3, 1, 2, 4] and [3, 1, 4, 2] are all possible, among which the last one is lexicographically largest one.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
Array may contain duplicate elements.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
vector<int> lexicographicallyLargest(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n && arr[j] % 2 == arr[j - 1] % 2)
            j++;
        sort(arr.begin() + i, arr.begin() + j, greater<int>());
        i = j;
    }
    return arr;
}
int main()
{

    vector<int> arr = {1, 3, 4, 2};
    vector<int> res = lexicographicallyLargest(arr);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i + 1 < res.size())
            cout << ", ";
    }
    cout << "]";
    return 0;
}