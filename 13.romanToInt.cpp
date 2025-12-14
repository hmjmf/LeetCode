#include <string>
#include <iostream>
#include <map>

class Solution {
public:
    std::map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int romanToInt(std::string s) {
      int result = 0;
        for (int i = 0; i < s.size(); i++) {
          int n = m[s[i]];
          if ((n % 10 == 0 || n == 1) && i + 1 < s.size() && (m[s[i+1]] == n * 10 || m[s[i+1]] == n * 5)) {
            n = -n;
          }
          std::cout << n << std::endl;
          result += n;
          
        }
        return result;
    }
};


int main() {
    Solution s;
    std::cout << s.romanToInt("MCMXCIV") << std::endl;
}
