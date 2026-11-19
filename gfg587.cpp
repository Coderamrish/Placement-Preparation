/*
Given an array arr[] of positive integers. Your need to sort them so that
The first part of the array contains odd numbers sorted in descending order.
The rest of the portion contains even numbers sorted in ascending order.
Examples:
Input: arr[] = [1, 2, 3, 5, 4, 7, 10]
Output: [7, 5, 3, 1, 2, 4, 10]
Explanation: 7, 5, 3, 1 are odd numbers in descending order and 2, 4, 10 are even numbers in ascending order.
Input: arr[] = [0, 4, 5, 3, 7, 2, 1]
Output: [7, 5, 3, 1, 0, 2, 4]
Explanation: 7, 5, 3, 1 are odd numbers in descending order and 0, 2, 4 are even numbers in ascending order.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 109
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortIt(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 1) {
            arr[i] *= -1;
        }
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            arr[i] *= -1;
        }
    }
}
int main() {
    vector<int> arr = {1, 2, 3, 5, 4, 7, 10};
    sortIt(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}