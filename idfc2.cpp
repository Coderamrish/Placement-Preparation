/*
2. Smallest Concatenated Adjacent Number
Given an array of positive integers, concatenate every pair of adjacent elements and return the smallest concatenated number. If the array size is odd, consider the last element as a single number.

Example:

Input:
[15, 24, 34, 10, 12, 21, 45, 67]

Output:
1221
Explanation:

Concatenated pairs:
15 + 24 = 1524
34 + 10 = 3410
12 + 21 = 1221
45 + 67 = 4567

Smallest = 1221
Constraints:

1 <= arr.size() <= 100000
1 <= arr[i] <= 10000
*/
#include<iostream>
#include<vector>
#include<climits>
#include<string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long answer = LLONG_MAX;
    for(int i = 0; i < n; i += 2) {
        long long value = 10;
        if(i + 1 < n) {
            long long second = arr[i + 1];
            long long temp  = second;
            long long multiplier = 1;
            while(temp > 0) {
                multiplier *= 10;
                temp /= 10;
            }
            value = (static_cast<long long> (arr[i]) * multiplier) + second;
        } else {
            value = arr[i];
        }
        answer = min(answer, value);
    }
    cout << answer << "\n";
    return 0;
}