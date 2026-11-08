/*
Geek has n documents that need to be scanned using two scanners. Scanner 1 takes s1 units of time to scan one document, while scanner 2 takes s2 units of time to scan one document.

Both scanners can operate simultaneously, and each scanner can scan only one document at a time. A scanner can start scanning its next document immediately after finishing the current one.

Find the minimum time required to scan all n documents.

Examples:

Input: n = 2, s1 = 2, s2 = 4
Output: 4
Explanation: We can either scan both documents using scanner 1, which takes 2 × 2 = 4 units of time, or scan one document using each scanner simultaneously, which takes max(2, 4) = 4 units of time. Both approaches require 4 units of time.
Input: n = 2, s1 = 1, s2 = 3
Output: 2
Explanation: The optimal approach is to scan both documents using scanner 1, which takes 2 × 1 = 2 units of time.
Constraints:

1 ≤ n, s1, s2 ≤ 106
1 ≤ s1 * n, s2 * n ≤ 109
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int minTime(int n, int s1, int s2)
{
    if (s1 > s2)
        swap(s1, s2);
    int low = 0;
    int high = n;
    int minTime = s2 * n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int time1 = mid * s1;
        int time2 = (n - mid) * s2;
        minTime = min(minTime, max(time1, time2));
        if (time1 <= time2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return minTime;
}
int main()
{
    int n = 2, s1 = 2, s2 = 4;
    cout << minTime(n, s1, s2) << endl;
    return 0;
}