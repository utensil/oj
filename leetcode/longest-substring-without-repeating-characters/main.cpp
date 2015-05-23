#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Submission begin

#include <algorithm>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeenPos;

    int curStartPos = 0;

    int maxLen = 0;

    for (size_t i = 0; i < s.size(); ++i) {
      char cur = s[i];

      // repeated
      if (lastSeenPos.count(cur) && lastSeenPos[cur] >= curStartPos) {
        // for (size_t j = curStartPos; j < i; ++j) {
        //   cout << s[j] << ",";
        // }
        // cout << endl;
        int len = i - curStartPos;

        maxLen = max(maxLen, len);
        curStartPos = lastSeenPos[cur] + 1;
      }

      lastSeenPos[cur] = i;
    }

    // for (size_t j = curStartPos; j < s.size(); ++j) {
    //   cout << s[j] << ",";
    // }
    // cout << endl;

    int len = s.size() - curStartPos;

    maxLen = max(maxLen, len);

    return maxLen;
  }
};

// Submission end

int main(int argc, char const *argv[]) {
  Solution s;

  vector<string> strs{"abcabcbb", "c", "aab", "abb", "abba"};
  vector<int> shouldBe{3, 1, 2, 2, 2};

  int i = 0;
  for (string str : strs) {
    int longestSubstring = s.lengthOfLongestSubstring(str);

    cout << str << ":" << longestSubstring << ":"
         << (longestSubstring == shouldBe[i]) << endl;
    ++i;
  }

  return 0;
}
