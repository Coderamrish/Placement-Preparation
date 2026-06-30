/*
Given two arrays a[] and b[] of size n and m respectively, find the minimum number of insertions and deletions on the array a[], required to make both the arrays identical.

Note: Array b[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at the end.

Examples :

Input: a[] = [1, 2, 5, 3, 1], b[] = [1, 3, 5]
Output: 4
Explanation:
Delete 2 from a: a[] = [1, 5, 3, 1]
Insert 3 after 1: a[] = [1, 3, 5, 3, 1]
Delete the last two elements: a[] = [1, 3, 5]
Total operations = 1 + 1 + 2 = 4.
Input: a[] = [1, 4], b[] = [1, 4]
Output : 0
Explanation: Both the Arrays are already identical.
 Constraints:
1 ≤ n, m ≤ 105
1 ≤ a[i], b[i] ≤ 105
Approach using the longest increasing subsequence the idea is to map each element of a[] to its position in b[] (if it exists) and then find the Longest Increasing Subsequence (LIS) of this mapped sequence. Since b[] is sorted and contains distinct elements, the LIS represents the maximum number of elements already in the correct order, while the remaining elements are handled through insertions and deletions.
TC:O(n log n) SC:O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n)) return 0;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    if(!(cin >> m)) return 0;
    vector<int>b(m);
    unordered_map<int, int>pos;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    vector<int>mapped;
    for(int i = 0; i < n; i++) {
        if(pos.find(a[i]) != pos.end()) {
            mapped.push_back(pos[a[i]]);
        }
    }
    vector<int>lis;
    for(int x : mapped) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if(it == lis.end()) 
            lis.push_back(x);
            else
            *it = x;
    }
    int L = lis.size();
    int operation  = (n - L) + (m - L);
    cout << operation << "\n";
    return 0;
}