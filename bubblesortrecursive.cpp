#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bubbleSort(int nums[], int n) {
    if(n == 1) return;
long long didSwap = 0;
for(int j = 0; j <= n - 2; j++) {
    if(nums[j] > nums[j + 1]) {
        int temp = nums[j + 1];
        nums[j + 1] = nums[j];
        nums[j] = temp;
        didSwap = 1;
    }
}
if(didSwap == 0) return;
bubbleSort(nums, n - 1);
}
int main() {
  int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    bubbleSort(nums, n);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}