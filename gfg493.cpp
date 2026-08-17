/*
Given an integer n such that there is n × n Snakes and Ladders board with cells numbered from 1 to n*n, find the minimum number of dice throws required to reach cell n*n starting from cell 1. Given two arrays of even lengths:

lad[], where each pair (lad[2*i], lad[2*i + 1]) represents the start and end of a ladder.
sn[], where each pair (sn[2*i], sn[2*i + 1]) represents the start and end of a snake.
If you land on the start cell of a snake or ladder, you must immediately move to its corresponding end cell.

You have complete control over the outcome of each dice throw i.e., in a single move,  you can move forward by any number of cells from 1 to 6. 

If it is impossible to reach cell n*n, return -1.

Examples:

Input: n = 6, lad[] = [3, 22, 5, 8, 11, 35, 20, 32], sn[] = [17, 4, 19, 7, 34, 1, 21, 9]
Output: 3
Explanation: For the 6 × 6 board, the minimum number of dice throws needed to reach cell 36 from cell 1 is 3.
One optimal path is:
Throw 4 to move from 1 to 5, then take the ladder to 8
Throw 3 to move from 8 to 11, then take the ladder to 35
Throw 1 to move from 35 to 36
So the destination is reached in 3 dice throws.

Input: n = 3, lad[] = [2, 8], sn[] = [7, 3]
Output: 2
Explanation: For the 3 × 3 board, the minimum number of dice throws needed to reach cell 9 from cell 1 is 2.
One optimal path is:
Throw 1 to move from 1 to 2, then take the ladder to 8.
Throw 1 to move from 8 to 9.
So the destination is reached in 2 dice throws.
Constraints:
1 ≤ n ≤ 103
1 ≤ lad.size(), sn.size(), lad[i], sn[i] ≤ n2 


*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int total = n * n;
    int l;
    cin >> l;
    vector<int> moves(total + 1, -1);
    for (int i = 0; i < l; i++)
    {
        int start, end;
        cin >> start >> end;
        moves[start] = end;
    }
    int s;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int start, end;
        cin >> start >> end;
        moves[start] = end;
    }
    vector<bool> visited(total + 1, false);
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty())
    {
        int pos = q.front().first;
        int throws = q.front().second;
        q.pop();
        if (pos == total)
        {
            cout << throws << endl;
            return 0;
        }
        for (int dice = 1; dice <= 6; dice++)
        {
            int next = pos + dice;
            if (next > total)
                break;
            if (!visited[next])
            {
                visited[next] = true;
                int destination = next;
                if (moves[next] != -1)
                {
                    destination = moves[next];
                }
                q.push({destination, throws + 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}