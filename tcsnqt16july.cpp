/*
You are given an array of integers of size $N$ and a target integer $T$. An "adjacent pair" is formed by any two elements that are next to each other in the array (i.e., $A[i]$ and $A[i+1]$).Your task is to find the maximum number of non-overlapping adjacent pairs such that the sum of the elements in each pair is an exact multiple of $T$.Since no element can be repeated or reused, once an element is included in a valid pair, it cannot be part of any other pair.Input FormatThe first line contains space-separated integers representing the elements of the array.The second line contains a single integer, representing the value of $T$.Output FormatPrint a single integer representing the maximum number of valid, non-overlapping adjacent pairs whose sum is a multiple of $T$.Constraints$2 \le N \le 10^5$$-10^9 \le A[i] \le 10^9$$1 \le T \le 10^9$Sample Test CasesSample Input 1Plaintext3 7 13 -3 5
10
Sample Output 1Plaintext2
Explanation 1The adjacent pair $(3, 7)$ at indices $0$ and $1$ has a sum of $10$, which is a multiple of $T = 10$.The next available adjacent pair $(13, -3)$ at indices $2$ and $3$ has a sum of $10$, which is also a multiple of $10$.No elements are repeated/reused across these pairs. Thus, the maximum count of such pairs is $2$.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, T;
    if(!(cin >> N >> T)) return 0;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
int cnt = 0;
for(int i = 0; i < N - 1;) {
    if((arr[i] + arr[i + 1]) % T == 0) {
        cnt++;
        i += 2;
    }
    else {
        i++;
    }
}
cout << cnt << endl;
return 0;
}