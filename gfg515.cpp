/*
Given a 2D grid mat[][] of size n × m consisting of characters and a string word, find all starting positions where the word occurs in the grid.

The word can be formed from any cell by moving in any of the 8 directions (2 horizontal, 2 vertical, and 4 diagonal) in a straight line without changing direction.
Each cell can be used at most once per occurrence.
Return all unique starting coordinates in lexicographically smallest order.
Examples :

Input: mat[][] = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}, word = "abe"
Output: {{0,0}, {0,2}, {1,0}}
Explanation: From (0,0) we can find "abe" in right-down diagonal. From (0,2) we can find "abe" in left-down diagonal. From (1,0) we can find "abe" in horizontally right direction.

Input: mat[][] = {{G,E,E,K,S,F,O,R,G,E,E,K,S}, {G,E,E,K,S,Q,U,I,Z,G,E,E,K}, {I,D,E,Q,A,P,R,A,C,T,I,C,E}}, word = "GEEKS"
Output: {{0,0}, {0,8}, {1,0}}
Explanation: From (0,0) we can find "GEEKS" horizontally right. From (0,8) we can find "GEEKS" horizontally right. From (1,0) we can find "GEEKS" horizontally right. 

Constraints:
1 <= n <= m <= 50
1 <= |word| <= 20
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans;
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != word[0])
                    continue;
                bool found = false;
                for (int d = 0; d < 8; d++) {
                    int x = i;
                    int y = j;
                    int k = 0;
                    while (k < word.size()) {
                        if (x < 0 || x >= n || y < 0 || y >= m ||
                            mat[x][y] != word[k]) {
                            break;
                        }
                        x += dx[d];
                        y += dy[d];
                        k++;
                    }
                    if (k == word.size()) {
                        found = true;
                        break;
                    }
                }
                if (found)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
int main() {
    Solution obj;
    vector<vector<char>> mat = {
        {'a', 'b', 'a', 'b'},
        {'a', 'b', 'e', 'b'},
        {'e', 'b', 'e', 'b'}
    };
    string word = "abe";
    vector<vector<int>> result = obj.searchWord(mat, word);
    for (auto& pos : result) {
        cout << "{" << pos[0] << ", " << pos[1] << "}" << endl;
    }
    return 0;
}