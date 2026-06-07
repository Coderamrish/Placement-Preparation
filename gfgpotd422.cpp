/*
Consider a special family of Engineers and Doctors with following rules :

Everybody has two children.
First child of an Engineer is an Engineer and second child is a Doctor.
First child of an Doctor is Doctor and second child is an Engineer.
All generations of Doctors and Engineers start with Engineer.
The first few levels of the family tree are shown below :


Given level and position (pos) of a person in above ancestor tree, find profession of the person.

Examples:

Input: level = 4, pos = 2
Output: Doctor
Explaination: It is shown in the tree given in question.
Input: level = 3, pos = 4
Output: Engineer
Explaination: Already given in the tree in question.
Constraints:
1 ≤ level ≤ 109
1 ≤ pos ≤ 109

TC:o(log(pos)) SC:O(1)
*/
#include <iostream>
#include <string>
using namespace std;
string profession(int level, int pos) {
    int x = pos - 1;
    int cnt = 0;
    while (x) {
        x = x & (x - 1);
        cnt++;
    }
    return (cnt % 2 == 0) ? "Engineer" : "Doctor";
}
int main() {
    int level, pos;
    cin >> level >> pos;
    cout << profession(level, pos);
    return 0;
}