/*
Given a positive integer N, print all of its  prime factors in increasing order.
if a prime factor occurs multiple times, print it multiple times.
Input Format:
A single integer N.
output Format:
Print the prime factors of N separated by spaces.
constraints:
2 <= N <= 10^9
Example 1:
Input:
60
output:
2 2 3 5
*/
#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    if(!(cin >> n)) return 0;
    while(n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }
    for(long long i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if(n > 2) {
        cout << n;
    }
    cout << "\n";
    return 0;
}

int main() {
    int n;
    cin >> n;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if(n > 1) 
    cout << n;
    return 0;
}