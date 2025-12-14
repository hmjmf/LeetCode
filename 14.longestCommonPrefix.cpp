#include <string>
#include <vector>
#include <iostream>
class Solution {
    public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
      std::string result = strs[0];
      return longestCommonPrefixPart(result, strs, 1);
    }

    std::string longestCommonPrefixPart(std::string s, std::vector<std::string>& strs, int n) {
      if (n >= strs.size() || s.size() == 0) {
        return s;
      }
      auto s2 = strs[n];
      s = std::string(s.begin(), s.begin() + std::min(s.size(), s2.size()));
      
      for (int i = 0; i < s.size() && i < s2.size(); i++) {
        if (s[i] != s2[i]) {
          s = std::string(s.begin(), s.begin() + i);
          break;
        }
      }

      return longestCommonPrefixPart(s , strs, n + 1);
    }
};

int main() {
  Solution s;
  std::vector<std::string> v = {"ab", "a"};
  std::cout << s.longestCommonPrefix(v) << std::endl;
}
