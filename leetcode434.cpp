/*
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
Answers within 10-5 of the actual value will be accepted as correct.
Example 1:
Input: hour = 12, minutes = 30
Output: 165
Example 2:
Input: hour = 3, minutes = 30
Output: 75
Example 3:
Input: hour = 3, minutes = 15
Output: 7.5
Constraints:
1 <= hour <= 12
0 <= minutes <= 59

Approach - Minute hand → minutes × 6
Hour hand → (hour % 12) × 30 + minutes × 0.5
Angle → abs(hourAngle − minuteAngle)
Answer → min(angle, 360 − angle)
 TC:O(1) SC:O(1)
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
    int hour, minutes;
    cin >> hour >> minutes;
    double minutesAngle = minutes * 6.0;
    double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
double angle = fabs(hourAngle - minutesAngle);
double result = min(angle, 360.0 - angle);
cout << result;
return 0;
}