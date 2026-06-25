/*
. Jack is always excited about sunday. It is favourite day, when he gets to play all day. And goes to cycling with his friends. So every time when the months starts he counts the number of sundays he will get to enjoy. Considering the month can start with any day, be it Sunday, Monday…. Or so on.
Count the number of Sunday jack will get within n number of days.
 Example 1:
Input 
mon-> input String denoting the start of the month.
13  -> input integer denoting the number of days from the start of the month.
Output :
2    -> number of days within 13 days.
Explanation:
The month start with mon(Monday). So the upcoming sunday will arrive in next 6 days. And then next Sunday in next 7 days and so on.
Now total number of days are 13. It means 6 days to first sunday and then remaining 7 days will end up in another sunday. Total 2 sundays may fall within 13 days. 
Test Case	Start Day	N (Days)	Expected Output
1	mon	13	2
2	sun	10	2
3	wed	5	1
4	sat	20	3
5	fri	30	5
Approach - To find the number of Sundays in $N$ days starting from a specific day:Find the offset to the first Sunday: Each starting day takes a different number of days to hit the first Sunday. For example, if the month starts on mon, the first Sunday is on day 7 (which is 6 days after the start). If it starts on sun, the first Sunday is on day 1 (0 days after the start).Count the first Sunday: If $N$ is greater than or equal to this offset, we count 1 Sunday and subtract the offset days from $N$.Count the remaining Sundays: Every subsequent Sunday occurs exactly every 7 days. So, we divide the remaining days by 7 and add it to our count.
TC:O(1) SC:O(1)
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main() {
    string start_day;
    int n;
    if (!(cin >> start_day >> n)) {
        return 0;
    }
    unordered_map<string, int> days_to_next_sunday = {
        {"sun", 0}, {"mon", 6}, {"tue", 5},
        {"wed", 4}, {"thu", 3}, {"fri", 2}, {"sat", 1}
    };
    if (days_to_next_sunday.find(start_day) == days_to_next_sunday.end()) {
        cout << 0 << endl;
        return 0;
    }
    int rem_days = n - days_to_next_sunday[start_day];
    int sunday_cnt = 0;
    if (rem_days >= 1) {
        sunday_cnt = 1 + (rem_days / 7);
    }
    cout << sunday_cnt << endl;
    return 0;
}