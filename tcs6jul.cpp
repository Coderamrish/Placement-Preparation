/*
K-th Best selling Product Problem Description Amazon is preparing for its annual shopping
festival and wants to identify its top performing items. given a stream of product sales data,
your task is to find the k-th best selling product. the k-th best selling product is defined as the product that 
ranks eaxctly at position k when all products are sorted by their sales volume in descending order.
to optimize for memory and performance with large datasets, you must implement you solution using a Min-Heap approach.
Input Format
The first line contains two integers N and K.
The second line contains N space-separated integers representing the sales count of each product.
Output Format

Print the sales count of the K-th best-selling product.

Constraints
1 <= K <= N <= 10^5
1 <= sales[i] <= 10^9
Sample Input 1
6 2
10 20 15 30 25 5
Sample Output 1
25
Explanation

Sorted in descending order:

30 25 20 15 10 5

The 2nd best-selling product has sales count 25.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int N, K;
if(!(cin >> N >> K)) return 0;
priority_queue<int, vector<int>, greater<int>> minHeap;
for(int i = 0; i < N; i++) {
    int sales;
    cin >> sales;
minHeap.push(sales);
if(minHeap.size() > K)
minHeap.pop();
}
cout << minHeap.top() << endl;
return 0;
}