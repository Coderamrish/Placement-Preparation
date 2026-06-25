/*
1.	Given an array Arr[] of N integers and a positive integer K, cyclically rotate the array clockwise by K.
Input Format:
•	First line: N (number of elements)
•	Second line: N space-separated integers (array elements)
•	Third line: K (number of rotations)
Output Format:
•	Rotated array as space-separated integers
Example
Sample Input
5
10 20 30 40 50
2
Output
40 50 10 20 30

Sample Input
5
1 2 3 4 5
3
Output
3 4 5 1 2

Approach - To cyclically rotate an array clockwise by $K$ positions, we can use an efficient in-place reversal algorithm.If we have an array and we rotate it by $K$, the elements from the back move to the front. However, if $K$ is greater than the size of the array $N$, rotating it $N$ times brings it back to its original state. Therefore, we should first normalize $K$ using $K = K \pmod N$.The 3-Step Reversal TrickWe can achieve this rotation in $\mathcal{O}(1)$ extra space by reversing parts of the array:Reverse the entire array.Reverse the first $K$ elements.Reverse the remaining $N-K$ elements.
TC:O(n) SC: O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    if(n == 0) return;
    k = k % n;
    if(k == 0) return;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}
int main() {
    int n;
    if(!(cin >> n)) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    rotateArray(arr, k);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    return 0;
}