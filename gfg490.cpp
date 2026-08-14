/*
There are n children standing in a queue, each assigned a number arr[i]. The teacher writes s on a paper and gives it to the first child.

Each child writes the sum of all numbers already on the paper and arr[i], then passes it to the next child.

Return true if x can be formed by adding some of the numbers written on the paper: else return false.

Input: arr[] = [1, 2, 4, 2], s = 1, x = 7
Output: true
Explanation: The first student gets 1 on paper and writes 2. The second student gets [1, 2] and writes 5. The third student gets [1, 2, 5] and writes 12. The final sequence of numbers on the paper is 1, 2, 5, 12, 22. Using 2 and 5 we can form 7. 
Input: arr[] = [51, 88], s = 100, x = 500
Output: false
Explanation: The final sequence of numbers on the paper is 100, 151, 339. Using these numbers we cannot form 500. 
Constraints:

1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 109
1 ≤ s ≤ 109
0 ≤ x ≤ 109
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> seq;
        long long sum = s;
        if (sum <= x)
            seq.push_back(sum);
        for (int val : arr) {
            long long cur = sum + val;
            if (cur > x)
                break;
            seq.push_back(cur);
            sum += cur;
        }
        unordered_set<long long> possible;
        possible.insert(0);
        for (long long val : seq) {
            vector<long long> newSums;
            for (long long curr : possible) {
                long long next = curr + val;
                if (next <= x) {
                    if (next == x)
                        return true;
                    newSums.push_back(next);
                }
            }
            for (long long v : newSums)
                possible.insert(v);
        }
        return possible.find(x) != possible.end();
    }
};