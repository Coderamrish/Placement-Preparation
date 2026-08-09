/*
Hospital system using priority queue

Hospital system can do two operation on basis of 2 number 1 and 2,
1 for entry of a patient severity 
2 for do the treatment 

Take input in one line where first integer denote the no of operation.
In output print the severity of listed patient if no patient is pending print "No Patient"
Input : 7 1 10 1 3 2 1 5 2 2 2
Output: 3 5 10 No patient

Explain:
1-> 10    add 10 in mean heap(10)
1-> 3.      add 3 in mean heap(3,10)
2 
So perform operation pop element from mean heap(priority queue) which is 3 
Then 
1-> 5   add 5 in priority queue(5,10)
2
So pop from mean heap and output is 5
2 
Again pop from mean heap and output is 10
2 
Now no element present in mean heap so output is No Patient 

Output: 3 5 10 No Patient
*/
#include<iostream>
#include<queue>
using namespace std;
void hospitalSystem(int operations) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < operations; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int severity;
            cin >> severity;
            pq.push(severity);
        }
        else if(type == 2) {
            if(pq.empty()) {
                cout << "No patient";
            }
            else {
                cout << pq.top();
                pq.pop();
            }
            if(i != operations - 1) {
                cout << " ";
            }
        }
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    hospitalSystem(n);
    return 0;
}