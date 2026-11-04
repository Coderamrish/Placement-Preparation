/*
Given an integer array arr[], find the XOR of the XOR values of all possible non-empty subarrays of the array.
Examples:
Input: arr[] = [1, 2, 3] 
Output: 2
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result: 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
Input: arr[] = [1, 2]
Output: 0
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2] = 2
Result: 1 ^ 3 ^ 2 = 0
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 109
*/
#include <iostream>
#include <vector>
using namespace std;
int subarrayXor(vector<int> &arr)
{
    int result = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 2 != 0 && (n - i) % 2 != 0)
        {
            result ^= arr[i];
        }
    }
    return result;
}
int main()
{
    vector<int> arr = {1, 2, 4};
    cout << subarrayXor(arr) << endl;
    return 0;
}