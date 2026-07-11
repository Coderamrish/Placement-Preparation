/*
Given an integer N, print the first N fibonacci series.
the fibonacci series starts with:
0 1 1 2 3 5 8 13....
each term is the sum of previous two terms 
Input format:
First line contains an integer N
output format:
print the first N fibonacci series
*/
#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    if(!(cin >> N) || N <=  0){
return 0;
    } 
    long long first = 0, second = 1, next;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            cout << first << " ";
        } else if(i == 1) {
            cout << second << " ";
        } else {
            next = first + second;
            cout << next << " ";
            first = second;
            second = next;
        }
    }
    return 0;
}