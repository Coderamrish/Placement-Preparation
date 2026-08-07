/*
A common coding interview problem is :
Given two integers L and R, compute:
where the integer binaary logarithm of x is the largest integer k such that:
Ex:
log2(1) = 0
log2(2) = 1
log2(3) = 1
log2(4) = 2
log2(5) = 2
Example:
input
L = 2
R = 8
values:
Number floor(log2)
2       1
3       1
4       2
5       2
6       2
7       2
8       3
Answer = 1+1+2+2+2+2+3 = 13
*/
#include<iostream>
#include<algorithm>
using namespace std;
long long solve(long long L, long long R) {
    long long ans = 0;
    for(int k = 0; k < 63; k++) {
        long long start = 1LL << k;
        long long end;
        if(k == 62) 
            end = (1LL << 62);
        else
        end = (1LL <<(k+ 1)) - 1;
        long long left = max(L, start);
        long long right = min(R, end);
        if(left <= right) {
            ans += (right - left + 1) * 1LL * k; 
        }
        if(start > R) break;
    }
    return ans;
}
int main() {
    long long L, R;
    cin >> L >> R;
    cout << solve(L, R);
    return 0;
}