/*
Given an array heights[] where each element represents the height of a histogram bar and the width of every bar is 1, find the area of the largest rectangle that can be formed inside the histogram.

Input Format
First line contains an integer N, representing the number of bars.
Second line contains N space-separated integers representing the heights of the histogram.
Output Format
Print a single integer representing the maximum rectangular area.
Constraints
1 <= N <= 10^5
0 <= heights[i] <= 10^4
Sample Input 1
6
2 1 5 6 2 3
Sample Output 1
10
Explanation

The largest rectangle is formed using the bars with heights 5 and 6.

Width = 2

Area = 5 × 2 = 10.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
long long getMaxArea(vector<int>& heights) {
    stack<int> s;
    long long max_area = 0;
    int n = heights.size();
    for(int i = 0; i <= n; i++) {
        int curr_height = (i == n) ? 0 : heights[i];
        while(!s.empty() && heights[s.top()] > curr_height) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : (i - s.top() - 1);
            long long area = (long long)height * width;
            max_area = max(max_area, area);
        }
        s.push(i);
    }
    return max_area;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    if(!(cin >> N)) return 0;
    vector<int> heights(N);
    for(int i =0 ; i < N; i++) {
        cin >> heights[i];
    }
    cout << getMaxArea(heights) << "\n";
    return 0;
}