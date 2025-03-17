#include <assert.h>

#include <string>
#include <vector>
#include <unordered_map>

#include "helper.h"

using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        std::vector<string> ret;

        add_char(digits, 0, "", ret);
        return ret;
    }
    void add_char(string digits, int index, std::string s, std::vector<string> &ret) {
        if (index == digits.size()) {
            ret.push_back(s);
            return;
        }
        auto c_v = get_char(digits.at(index));
        for (int i = 0; i < c_v.size(); i++) {
            add_char(digits, index + 1, s + std::string(1, c_v[i]), ret);
        }
    }

    vector<char> get_char(char c) {
        static std::unordered_map<char, vector<char>> m = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };
        vector<char> r = m.at(c);
        return r;
    }
};

int main() {
    Solution s;
    print_vector(s.letterCombinations("23"));
    // std::cout << s.letterCombinations("23") << std::endl;
    // std::cout << s.isMatch("aa", "a*") << std::endl;
    // std::cout << s.isMatch("aa", ".*") << std::endl;
}
