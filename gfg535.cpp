/*
Given an integer array arr[] and a 2D array queries[][] containing q queries, where each query is one of the following two types:

Type 1: [0, l, r] -> Return the GCD of all elements in the range [l, r] (both inclusive).
Type 2: [1, index, value] -> Update arr[index] to value.
Return an array containing the answers to all Type 1 queries in the order they appear in queries[][].

Note: Use 0-based indexing.

Examples:

Input: arr[] = [2, 3, 4, 6, 8, 16], q = 3, queries[][] = [[0, 0, 2], [1, 3, 8], [0, 2, 5]]
Output: [1, 4]
Explanation: Initially, arr[] = [2, 3, 4, 6, 8, 16].
Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [2, 3, 4]. The GCD is 1.
Query [1, 3, 8]: Update arr[3] from 6 to 8. The array becomes [2, 3, 4, 8, 8, 16].
Query [0, 2, 5]: Find the GCD of the subarray arr[2...5] = [4, 8, 8, 16]. The GCD is 4.
Therefore, the answers to all Type 0 queries are [1, 4].
Input: arr[] = [12, 18, 24, 30, 36], q = 4, queries[][] = [[0, 1, 3], [1, 2, 15], [0, 0, 2], [0, 2, 4]]
Output: [6, 3, 3]
Explanation: Initially, arr[] = [12, 18, 24, 30, 36].
Query [0, 1, 3]: Find the GCD of the subarray arr[1...3] = [18, 24, 30]. The GCD is 6.
Query [1, 2, 15]: Update arr[2] from 24 to 15. The array becomes [12, 18, 15, 30, 36].
Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [12, 18, 15]. The GCD is 3.
Query [0, 2, 4]: Find the GCD of the subarray arr[2...4] = [15, 30, 36]. The GCD is 3.
Therefore, the answers to all Type 0 queries are [6, 3, 3].
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ q ≤ 105
0 ≤ l, r, index ≤ arr.size()-1
1 ≤ arr[i], value ≤ 105
*/
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int getMid(int s, int e)
{
    return s + (e - s) / 2;
}
int buildSegmentTree(vector<int> &arr, int ss, int se, vector<int> &st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = gcd(buildSegmentTree(arr, ss, mid, st, si * 2 + 1),
                 buildSegmentTree(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}
int findGcd(int ss, int se, int qs, int qe, int si, vector<int> &st)
{
    if (ss > qe || se < qs)
        return 0; 
    if (qs <= ss && qe >= se)
        return st[si];
    int mid = getMid(ss, se);
    return gcd(findGcd(ss, mid, qs, qe, 2 * si + 1, st), findGcd(mid + 1, se, qs, qe, 2 * si + 2, st));
}
void updateValueUtil(int ss, int se, int index, int new_val, int si, vector<int> &st)
{
    if (index < ss || index > se)
        return;
    if (ss == se)
    {
        st[si] = new_val;
        return;
    }
    int mid = getMid(ss, se);
    if (index <= mid)
        updateValueUtil(ss, mid, index, new_val, 2 * si + 1, st);
    else
        updateValueUtil(mid + 1, se, index, new_val, 2 * si + 2, st);
    st[si] = gcd(st[2 * si + 1], st[2 * si + 2]);
}
void updateValue(int index, int new_val, vector<int> &arr, vector<int> &st, int n)
{
    arr[index] = new_val;
    updateValueUtil(0, n - 1, index, new_val, 0, st);
}
vector<int> processQueries(vector<int> &arr, vector<vector<int>> &q)
{
    int n = arr.size();
    int x = 2 * (int)pow(2, ceil(log2(n))) - 1;
    vector<int> st(x);
    buildSegmentTree(arr, 0, n - 1, st, 0);
    vector<int> result;
    for (auto &query : q)
    {
        int type = query[0];
        if (type == 1)
        {
            int index = query[1];
            int new_val = query[2];
            updateValue(index, new_val, arr, st, n);
        }
        else
        {
            int l = query[1];
            int r = query[2];
            result.push_back(findGcd(0, n - 1, l, r, 0, st));
        }
    }
    return result;
}
int main()
{
    vector<int> arr = {2, 3, 4, 6, 8, 16};
    vector<vector<int>> q = {
        {2, 0, 2}, 
        {1, 3, 8}, 
        {2, 2, 5}  
    };
    vector<int> ans = processQueries(arr, q);
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}