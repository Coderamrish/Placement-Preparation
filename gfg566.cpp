/*
Given an integer array files[], where files[i] represents the size of the i-th file, merge all the files into a single file with the minimum total computation cost.
The cost of merging two files of sizes x and y is x + y. After merging, a new file of size x + y is created, which can be merged further with other files.
Return the minimum total cost required to merge all the files.
Note: It is guaranteed that the minimum total computation cost fits within a 32-bit signed integer.
Examples:
Input: files[] = [3, 2, 4]
Output: 14
Explanation: There are different ways to combine these files. Optimal method is given below:
Lightbox
Input: files[] = [2, 3, 6, 5, 7, 4]
Output: 68
Explanation: There are different ways to combine these files. Optimal method is given below:
Constraints:
1 ≤ files.size() ≤ 105
1 ≤ files[i] ≤ 103
*/
#include<functional>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int minComputationCost(vector<int> files) {
    priority_queue<int, vector<int>, greater<int>> pq(files.begin(), files.end());
    int totalCost =0;
while(pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    totalCost += a + b;
    pq.push(a + b);
}
return totalCost;
}
int main() {
    vector<int> files = {3, 2, 4};
    cout << minComputationCost(files) << endl;
    return 0;
}