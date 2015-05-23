#include <vector>
using namespace std;
#include <iostream>

// Submission begin

#include <unordered_map>

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {

    int i1 = -1;
    int i2 = -1;

    unordered_map<int, size_t> num2posMap;

    for (size_t i = 0; i < nums.size(); ++i) {
      // Overwrite on duplication is good enough for finding 1 numNeeded.
      num2posMap[nums[i]] = i;
    }

    for (size_t j = 0; j < nums.size(); ++j) {

      int numNeeded = target - nums[j];

      auto numFound = num2posMap.find(numNeeded);

      if (numFound != num2posMap.end() && numFound->second != j) {
        i1 = j;
        i2 = numFound->second;
        break;
      }
    }

    vector<int> indexes;

    // +1: Please note that your returned answers (both index1 and index2) are
    // not zero-based.
    indexes.push_back(i1 + 1);
    indexes.push_back(i2 + 1);

    // Skip result check: You may assume that each input would have exactly one
    // solution.
    return indexes;
  }
};

// Submission end

int main(int argc, char const *argv[]) {

  Solution s;

  vector<int> v{3, 2, 4};
  int target = 6;

  auto indexes = s.twoSum(v, target);
  int i1 = indexes[0];
  int i2 = indexes[1];

  cout << i1 << "," << i2 << endl;

  cout << v[i1 - 1] << "+" << v[i2 - 1] << "=" << target << endl;

  return 0;
}
