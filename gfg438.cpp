/*
There are infinitely many people standing in a row, indexed from 1. The strength of the person at index i is i².

Given a strength p, determine the maximum number of people that can be defeated. A person with strength x can be defeated only if p ≥ x, after which the strength p decreases by x.

Examples :

Input: p = 14
Output: 3
Explanation: The strengths of the first few people are 1, 4, 9, 16, .... Defeating the first three people consumes 1 + 4 + 9 = 14 strength, leaving 0. Therefore, the maximum number of people that can be defeated is 3.
Input: p = 10
Output: 2
Explanation: After defeating people with strengths 1 and 4, the remaining strength is 5, which is less than the next required strength 9.
Constraints:
1 ≤ p ≤ 3*108

Approach1 - using the simulate defeating people TC:O(underroot p) sc:O(1)
approach 2 - using the inary searh on the perople tc :O(log p) SC:O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
int maxPeopleDefeated(int p) {
    int cnt = 0, i = 1;
    while(i * i <= p) {
        p -= i * i;
        cnt++;
        i++;
    }
    return cnt;
}


// approach 2 
 int sum(int h) {
        return h * (h + 1) * (2 * h + 1) / 6;
    }
int maxPeopleDefeat(int P) {
    int low = 0, high = 1000;
    int ans = 0;
    while(low <= high) {
        int mid = low +(high - low) / 2;
        if(sum(mid) <= P) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int main() {
int P, p;
cin >> P >> p;
cout << maxPeopleDefeat(p) ,maxPeopleDefeated(P);
return 0;
}