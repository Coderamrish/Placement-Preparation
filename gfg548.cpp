/*
Given an integer array arr[] where the two parts around a break point are individually sorted, merge them into a single sorted array.  The break point can be anywhere in the array, including at the beginning or end.
Examples:
Input: arr[] = [2, 3, 8, -1, 7, 10]
Output: [-1, 2, 3, 7, 8, 10] 
Explanation: [2, 3, 8] and [-1, 7, 10] are sorted in the original array. The overall sorted version is [-1 2 3 7 8 10].
Input: arr[] = [-4, 6, 9, -1, 3]
Output: [-4, -1, 3, 6, 9]
Explanation: [-4, 6, 9] and [-1, 3] are sorted in the original array. The overall sorted version is [-4 -1 3 6 9].
Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: One part is empty and the other part is whole array which is already sorted.
Constraints:
1 ≤ arr.size() ≤ 106
-105 ≤ arr[i] ≤ 105
*/
#include <iostream>
#include <vector>
using namespace std;
void mergeTwoParts(vector<int> &arr)
{
    int n = arr.size();
    int index = 0;
    vector<int> temp(n);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            index = i + 1;
            break;
        }
    }
    if (index == 0)
        return;
    int i = 0, j = index, k = 0;
    while (i < index && j < n)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i < index)
        temp[k++] = arr[i++];
    while (j < n)
        temp[k++] = arr[j++];
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}
int main()
{
    vector<int> arr = {2, 3, 8, -1, 7, 10};
    int n = arr.size();
    mergeTwoParts(arr);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}