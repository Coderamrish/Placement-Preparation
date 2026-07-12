/*
There are N passengers who need to travel.
A car can carry 4 passengers and produce X units of pollution.
A van can carry 100 passengers and produce Y units of pollution.
You may use any number of cars and vans.
your task is to transport ar least N passengers while producing the minimum total pollution.
Input format:
First line contains an integer T, the number of test cases
each of the  next T lines contains three integers.
N X Y
where 
N = number of paasengers 
X = Pollution produced by one car
Y = pollution produced by one van
Output format:
Print the minimum pollution for each test case.
Example:
Input:
3
120 3 50
400 20 40
205 5 15
output:
65
160
40
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        long long N, X, Y;
        cin >> N >> X >> Y;
        long long ans = 1e18;
        long long maxVans = (N + 99) / 100 + 1;
for(long long vans = 0; vans <= maxVans; vans++) {
    long long remaining = max(0LL, N - vans * 100);
    long long cars = (remaining + 3) / 4;
    ans = min(ans, vans*Y+cars*X);
}
cout << ans << "\n";
    }
    return 0;
}