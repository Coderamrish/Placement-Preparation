/*
Given an array arr[], choose any subset of elements (possibly all elements) such that the XOR of the chosen elements is maximized.
Examples:
Input : arr[] = [2, 4, 5]
Output: 7
Explanation: The subset {2, 5} has the maximum XOR value.
Input : arr[] = [9, 8, 5]
Output: 13
Explanation: The subset {8, 5} has the maximum XOR value.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<bitset>
using namespace std;
int maxSubsetXor(vector<int>& arr) {
    int n = arr.size();
    int index = 0;
    for(int bit = 31; bit >= 0 && index < n; bit--) {
        int maxIndex = -1;
        for(int i = index; i < n; i++) {
            if((arr[i] & (1 << bit))) {
                if(maxIndex == -1 || arr[i] > arr[maxIndex])
                maxIndex = i;
            }
        }
        if(maxIndex == -1) continue;
        swap(arr[index], arr[maxIndex]);
        for(int i = 0; i < n; i++) {
            if(i != index && (arr[i] & (1 << bit))) {
                arr[i] ^= arr[index];
            }
        }
        index++;
    }
    int ans = 0;
    for(int num : arr) 
    ans ^= num;
    return ans;
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
    cout << maxSubsetXor(arr);
    return 0;
}