/*
Given an array arr[] of non-negative integers, where each element represents the maximum number of steps you can jump forward from that index, determine the minimum number of jumps required to reach the last index starting from the first index. If it is not possible to reach the end, return -1.
Examples: 
Input: arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
Output: 3 
Explanation: First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 

Test Case	Input String	Expected Output
1              [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]         3
2                   [1, 4, 3, 2, 6, 7]                        2
                3                  [0, 10, 20]                                 0
                4                     [0, 3, 10, 20]                          0
                5                     [1, 10, 20,5,6,61]                   2
Approach - Instead of using Dynamic Programming which takes $O(n^2)$ time, we can solve this in $O(n)$ time and $O(1)$ space using a greedy BFS-like approach. We keep track of the farthest point we can reach with our current number of jumps.We maintain three variables:jumps: Total jumps taken so far.current_end: The maximum index we can reach with the current number of jumps.farthest: The maximum index we can reach overall from any of the indices we have visited so far.As we iterate through the array:We constantly update farthest = max(farthest, i + arr[i]).If we reach current_end, it means we must make another jump to move further. We increment jumps and update current_end = farthest.If at any point i becomes greater than farthest, it means we are stuck and cannot reach the end, so we return -1.
TC:O(n) SC:O(n)
*/
#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<sstream>
using namespace std;
int minJumps(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return 0;
    if(arr[0] == 0) return -1;
    int jumps = 0;
    int current_end = 0;
    int farthest = 0;
    for(int i = 0; i < n - 1; i++) {
        farthest = max(farthest, arr[i] + i);
        if(i == current_end) {
            jumps++;
            current_end = farthest;
            if(current_end >= n - 1) {
                return jumps;
            }
        }
        if(i >= farthest) {
            return -1;
        }
    }
    return -1;
}
int main() {
  string input;
    if (!getline(cin, input)) return 0;
    for (char &c : input) {
        if (c == '[' || c == ']' || c == ',') {
            c = ' ';
        }
    }
    vector<int> arr;
    stringstream ss(input);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    cout << minJumps(arr) << endl;
    return 0;
}