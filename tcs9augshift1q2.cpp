/*
You are given a sequence of integers as a single line of space separated values. The number of elements is not given explicitly. 
Your task is to sort the array using merge sort and count the number of swaps
. Return the total count. 
Test Case 1
 Input = 5 3 2 4 1
output =  8.
Test case 2
Input = 8 7 6 5
Output = 6
*/
#include <iostream>
#include <vector>
using namespace std;
long long mergeArray(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    long long count = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
            count += (mid - left + 1);
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return count;
}
long long mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) {
        return 0;
    }
    int mid = low + (high - low) / 2;
    long long count = 0;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += mergeArray(arr, low, mid, high);
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
    int x;
    while (cin >> x) {
        nums.push_back(x);
    }
    if (nums.empty()) {
        cout << 0 << endl;
        return 0;
    }
    long long result = mergeSort(nums, 0, nums.size() - 1);
    cout << result << endl;
    return 0;
}