/*
Given a Time in 12-hour AM/PM format, convert it to 24 hour military time Note : 12:00 AM on a 12 -hour clock is 00:00 on a 24-hour clock.
Description Complete the time conversion function
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    string period = s.substr(8, 2);
    int hour = stoi(s.substr(0, 2));
    if (period == "AM") {
        if (hour == 12)
            hour = 0;
    } else {  
        if (hour != 12)
            hour += 12;
    }
    if (hour < 10)
        cout << "0";
    cout << hour;
    cout << s.substr(2, 6);
    return 0;
}