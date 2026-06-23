/*
Two integres N and S are given.
starting from S, find prime numbers and count them until the Nth prime is reached.
Once the Nth prime is found.
Take that prime
take the next two consective prime numbers.
return the sum of all three primes.
Example 
input:
N = 10
S = 7
Prime numbers starting from 7:
7,11,13,17,19,23,29,31,37,41
10th prime = 41
Next two primes:
43, 47
Sum:
41+43+47 = 131
output: 
131
*/
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int num) {
    if(num <= 1) return false;
    if(num == 2 || num == 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int i = 5; i * i <= num; i += 6) {
        if(num % i == 0 || num % (i + 2) == 0){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, S;
    cin >> N >> S;
    int cnt = 0;
    int curr = S;
    int nth_prime = 0;
    while(cnt < N) {
        if(isPrime(curr)) {
cnt++;
if(cnt == N) {
    nth_prime = curr;
    break;
}
        }
        curr++;
    }
    int next_prime_1 = nth_prime + 1;
    while(!isPrime(next_prime_1)) {
        next_prime_1++;
    }
    int next_prime2 = next_prime_1 + 1;
while(!isPrime(next_prime2)) {
    next_prime2++;
}
long long total_sum = (long long)nth_prime + next_prime_1 + next_prime2;
cout << total_sum << "\n";
return 0;
}