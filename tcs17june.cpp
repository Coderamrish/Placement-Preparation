/*
An array of size N contains from  0 to N - 1. Exactly one number is repeated and exactly one number is missing 
Find and print:
1. The duplicate number
2. The misssing number

Input format First line will contains integer N
second line contains N space separated integers 
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> freq(N,0);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int duplicate = -1, missing = -1;
    for(int i = 0; i <N; i++) {
        if(freq[i] == 2) 
        duplicate = i;
        else if(freq[i] == 0)
        missing = i;
    }
cout << duplicate << endl;
cout << missing << endl;
return  0;
}