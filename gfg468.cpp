/*
Given an array arr[ ] consisting of distinct integers, check if the given array can represent preorder traversal of a BST.

Examples :

Input: arr[] = [2, 4, 3]
Output: true
Explaination: Given arr[] can represent preorder traversal of following BST:
 
Input: arr[] = [2, 4, 1]
Output: false
Explaination: Given arr[] cannot represent preorder traversal of a BST.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
*/
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<climits>
using namespace std;
 bool canPreorder(vector<int> & arr) {
    int n = arr.size();
stack<int> st;
int root = INT_MIN;
for(int i = 0; i < n; i++) {
    if(arr[i] < root) return false;
    while(!st.empty() && arr[i] > st.top()) {
        root = st.top();
        st.pop();
    }
    st.push(arr[i]);
}
return true;
 }
 int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i <  n; i++) {
        cin >> arr[i];
    }
    if( canPreorder(arr)) {
cout << "True" << "\n";
    } else {
        cout << "False" << "\n";
    }
    return 0;
 }

