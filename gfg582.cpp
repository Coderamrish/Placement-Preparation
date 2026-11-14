/*
Given three stacks s1, s2, and s3, represented by arrays where the first element of each array represents the top of the corresponding stack.
Find the maximum possible equal sum(sum of all elements) of all three stacks by removing zero or more elements from the top of each stack.
If it is not possible to make the sum of all three stacks equal, return 0.
Examples:
Input: s1 = [3, 2, 1, 1, 1], s2 = [4, 3, 2], s3 = [2, 5, 4, 1]
Output: 5
Explanation: Remove 3 from s1, 4 from s2, and 2, 5 from s3. The remaining sums of all three stacks are equal to 5.
pop
Input: s1 = [4,7], s2 = [10], s3 = [1,2,3]
Output: 0
Explanation: It is not possible to make the sums of all three stacks equal by removing elements from their tops.
Constraints:
1 ≤ s1.size(), s2.size(), s3.size() ≤ 5 * 105
1 ≤ s1[i], s2[i], s3[i] ≤ 103
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3)
{
    vector<int> suffix(s3.size() + 1, 0);
    int sum1 = 0;
    unordered_set<int> st1;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        sum1 += s1[i];
        st1.insert(sum1);
    }
    int sum2 = 0;
    unordered_set<int> st2;
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        sum2 += s2[i];
        st2.insert(sum2);
    }
    for (int i = s3.size() - 1; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + s3[i];
    }
    for (int i = 0; i < suffix.size(); i++)
    {
        if (st1.find(suffix[i]) != st1.end() && st2.find(suffix[i]) != st2.end())
        {
            return suffix[i];
        }
    }
    return 0;
}
int main()
{
    vector<int> s1 = {3, 2, 1, 1, 1};
    vector<int> s2 = {4, 3, 2};
    vector<int> s3 = {1, 1, 4, 1};
    cout << maxEqualSum(s1, s2, s3) << endl;
    return 0;
}