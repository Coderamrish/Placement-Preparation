/*
You are given a binary string s of length n, where:

'1' represents an active section.
'0' represents an inactive section.
You can perform at most one trade to maximize the number of active sections in s. In a trade, you:

Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
Additionally, you are given a 2D array queries, where queries[i] = [li, ri] represents a substring s[li...ri].

For each query, determine the maximum possible number of active sections in s after making the optimal trade on the substring s[li...ri].

Return an array answer, where answer[i] is the result for queries[i].

Note

For each query, treat s[li...ri] as if it is augmented with a '1' at both ends, forming t = '1' + s[li...ri] + '1'. The augmented '1's do not contribute to the final count.
The queries are independent of each other.
 

Example 1:

Input: s = "01", queries = [[0,1]]

Output: [1]

Explanation:

Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Example 2:

Input: s = "0100", queries = [[0,3],[0,2],[1,3],[2,3]]

Output: [4,3,1,1]

Explanation:

Query [0, 3] → Substring "0100" → Augmented to "101001"
Choose "0100", convert "0100" → "0000" → "1111".
The final string without augmentation is "1111". The maximum number of active sections is 4.

Query [0, 2] → Substring "010" → Augmented to "10101"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "1110". The maximum number of active sections is 3.

Query [1, 3] → Substring "100" → Augmented to "11001"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Query [2, 3] → Substring "00" → Augmented to "1001"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Example 3:

Input: s = "1000100", queries = [[1,5],[0,6],[0,4]]

Output: [6,7,2]

Explanation:

Query [1, 5] → Substring "00010" → Augmented to "1000101"
Choose "00010", convert "00010" → "00000" → "11111".
The final string without augmentation is "1111110". The maximum number of active sections is 6.

Query [0, 6] → Substring "1000100" → Augmented to "110001001"
Choose "000100", convert "000100" → "000000" → "111111".
The final string without augmentation is "1111111". The maximum number of active sections is 7.

Query [0, 4] → Substring "10001" → Augmented to "1100011"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.

Example 4:

Input: s = "01010", queries = [[0,3],[1,4],[1,3]]

Output: [4,4,2]

Explanation:

Query [0, 3] → Substring "0101" → Augmented to "101011"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "11110". The maximum number of active sections is 4.

Query [1, 4] → Substring "1010" → Augmented to "110101"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "01111". The maximum number of active sections is 4.

Query [1, 3] → Substring "101" → Augmented to "11011"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.

 

Constraints:

1 <= n == s.length <= 105
1 <= queries.length <= 105
s[i] is either '0' or '1'.
queries[i] = [li, ri]
0 <= li <= ri < n
*/
#include <ranges>
struct Group {
  int start;
  int length;
};
class SparseTable {
 public:
  SparseTable(const vector<int>& nums)
      : n(nums.size()), st(std::bit_width(n) + 1, vector<int>(n + 1)) {
    copy(nums.begin(), nums.end(), st[0].begin());
    for (int i = 1; i <= bit_width(n); ++i)
      for (int j = 0; j + (1 << i) <= n; ++j)
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }
  int query(unsigned l, unsigned r) const {
    const int i = bit_width(r - l + 1) - 1;
    return max(st[i][l], st[i][r - (1 << i) + 1]);
  }
 private:
  const unsigned n;
  vector<vector<int>> st;
};
class Solution {
 public:
  vector<int> maxActiveSectionsAfterTrade(string s,
                                          vector<vector<int>>& queries) {
    const int n = s.length();
    const int ones = ranges::count(s, '1');
    const auto [zeroGroups, zeroGroupIndex] = getZeroGroups(s);
    if (zeroGroups.empty())
      return vector<int>(queries.size(), ones);
    const SparseTable st(getZeroMergeLengths(zeroGroups));
    vector<int> ans;
    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      const int left = zeroGroupIndex[l] == -1
                           ? -1
                           : (zeroGroups[zeroGroupIndex[l]].length -
                              (l - zeroGroups[zeroGroupIndex[l]].start));
      const int right = zeroGroupIndex[r] == -1
                            ? -1
                            : (r - zeroGroups[zeroGroupIndex[r]].start + 1);
      const auto [startAdjacentGroupIndex, endAdjacentGroupIndex] =
          mapToAdjacentGroupIndices(
              zeroGroupIndex[l] + 1,
              s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1);
      int activeSections = ones;
      if (s[l] == '0' && s[r] == '0' &&
          zeroGroupIndex[l] + 1 == zeroGroupIndex[r])
        activeSections = max(activeSections, ones + left + right);
      else if (startAdjacentGroupIndex <= endAdjacentGroupIndex)
        activeSections = max(
            activeSections,
            ones + st.query(startAdjacentGroupIndex, endAdjacentGroupIndex));
      if (s[l] == '0' &&
          zeroGroupIndex[l] + 1 <=
              (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1))
        activeSections =
            max(activeSections,
                ones + left + zeroGroups[zeroGroupIndex[l] + 1].length);
      if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1)
        activeSections =
            max(activeSections,
                ones + right + zeroGroups[zeroGroupIndex[r] - 1].length);
      ans.push_back(activeSections);
    }
    return ans;
  }
 private:
  pair<vector<Group>, vector<int>> getZeroGroups(const string& s) {
    vector<Group> zeroGroups;
    vector<int> zeroGroupIndex;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        if (i > 0 && s[i - 1] == '0')
          ++zeroGroups.back().length;
        else
          zeroGroups.push_back({i, 1});
      }
      zeroGroupIndex.push_back(zeroGroups.size() - 1);
    }
    return {zeroGroups, zeroGroupIndex};
  }
  vector<int> getZeroMergeLengths(const vector<Group>& zeroGroups) {
    vector<int> zeroMergeLengths;
    for (const auto& [a, b] : zeroGroups | views::pairwise)
      zeroMergeLengths.push_back(a.length + b.length);
    return zeroMergeLengths;
  }
  pair<int, int> mapToAdjacentGroupIndices(int startGroupIndex,
                                           int endGroupIndex) {
    return {startGroupIndex, endGroupIndex - 1};
  }
};