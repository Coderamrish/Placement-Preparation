/*
Andy wants to go on a vacation to de-stress himself. He can take only one continous vacation.
during the next N days, where the days are numbered from 1 to N.
andy already has M obligations scheduled on specific days. the i-th obligation is on day D[i]. to extend his  vacation , any is allowed to cancel at most K obligations.
your task is to determine the maximum number of cnsecutive vacation days andy can take after cancelling at most K obligations.
Input format:
The first line contains three integers:
N - Total number of days
M - number of schedule obligations.
K- Maximum number of obligations that can be canceled.
The Second line contains M space-separated integers representing the days on which the obligation are scheduled
Constraints:
1 <= N <= 10^9
0 <= M <= 2 * 10 ^5
0 <= K <= M
1 <= D[i] <= N
All obligation days are distinct.
sample input:
20 5 2
3 8 12 15 18
output:
11
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    int M, K;
    if(!(cin >> N >> M >> K)) return 0;
    vector<long long> d(M+2);
    for(int i = 1; i <= M; i++) 
        cin >> d[i];
        sort(d.begin() + 1, d.begin() + M + 1);
        d[0] = 0;
        d[M+1] = N + 1;
        long long ans = 0;
        for(int i = 0; i + K + 1 <= M + 1; i++) {
            ans = max(ans,d[i+K+1] - d[i]-1);
        }
        cout << ans;
        return 0;
    }
