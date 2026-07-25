/*
Given an integer array arr[] representing the nodes of a Complete Binary Tree in level order traversal, return the nodes at each level in sorted ascending order.

For every level of the binary tree, sort the values present at that level independently and return the resulting levels as a 2D array, where the i-th row contains the sorted values of the i-th level.

Examples:

Input: arr[] = [7, 6, 5, 4, 3, 2, 1]
Output: [[7], [5, 6], [1, 2, 3, 4]]
Explanation: The complete binary tree formed from the given level order traversal is:   
        
The nodes at each level after sorting are:
Level 0: [7]
Level 1: [5, 6]
Level 2: [1, 2, 3, 4]
Input: arr[] = [7, 16, 1, 4, 13]
Output: [[7], [1, 16], [4, 13]]
Explanation: The complete binary tree formed from the given level order traversal is:      
           
The nodes at each level after sorting are:
Level 0: [7]
Level 1: [1, 16]
Level 2: [4, 13]

Constraints:

1 ≤ arr.size() ≤ 104
1 ≤ arr[i] ≤ 109

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
int n;
cin >> n;
vector<int> arr(n);
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}
int currentIndex = 0;
int level = 0;
while(currentIndex < n) {
    int nodesInLevel = 1 << level;
    int levelEnd = min(currentIndex + nodesInLevel, n);
    sort(arr.begin() + currentIndex, arr.begin() + levelEnd);
    for(int i = currentIndex; i < levelEnd; i++) {
        cout << arr[i];
        if(i != levelEnd - 1)
        cout << " ";
    }
    cout << "\n";
    currentIndex = levelEnd;
    level++;
}
return 0;
}