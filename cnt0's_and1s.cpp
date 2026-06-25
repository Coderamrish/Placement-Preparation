/*
. Maximum consecutive one’s (or zeros) in a binary array
Given a binary array arr[] consisting of only 0s and 1s, find the length of the longest contiguous sequence of either 1s or 0s in the array.
Examples : 
Input: arr[] = [0, 1, 0, 1, 1, 1, 1]
Output: 4
Explanation: The maximum number of consecutive 1’s in the array is 4 from index 3-6.
Input: arr[] = [0, 0, 1, 0, 1, 0]
Output: 2
Explanation: The maximum number of consecutive 0’s in the array is 2 from index 0-1.
Input: arr[] = [0, 0, 0, 0]
Output: 4
Explanation: The maximum number of consecutive 0’s in the array is 4.

Test Case	Input String	Expected Output
              1                    [0, 1, 0, 1, 1, 1, 1]            4
              2                       [0,0,1,0,1,0]                  2
              3                         [0,0,0,0]                      4
              4                         [1,1,1,0,0,1]                3
              5                         [0,0,1,0,0,0]                3

Approach -- Traverse the array once
Keep:
currCount → current consecutive count
maxCount → maximum found so far
Reset currCount when the value changes
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
    string input;
    getline(cin, input);
    for (char &c : input) {
        if (c == '[' || c == ']' || c == ',')
            c = ' ';
    }
    vector<int> arr;
    stringstream ss(input);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    if (arr.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int maxCount = 1, currCount = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            currCount++;
        } else {
            currCount = 1;
        }
        maxCount = max(maxCount, currCount);
    }
    cout << maxCount << endl;
    return 0;
}