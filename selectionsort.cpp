/*
Medium level question:

Selection sort performing for p no of  pass

Input:
n= 5(size of array)
p = 3(no of pass)
arr [] = 5 1 7 3 2 
 
Output:
1 2 3 7 5 

Explain: 
After 1st pass
1 5 7 3 2
After 2nd pass
1 2 7 3 5
After 3rd pass
1 2 3 7 5
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void insertionSort(vector<int> & arr, int n, int p) {
    for(int i = 1; i <= p && i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void selectionSort(vector<int>& arr, int n, int p) {
    for(int i = 0; i < p && i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1;  j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main() {
    int n;
    cin >> n;
    int p1, p2;
    cin >> p1 >> p2;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, n, p1);
    selectionSort(arr, n, p2);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}