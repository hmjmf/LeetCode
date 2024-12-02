#include <vector>
#include <assert.h>
#include "helper.h"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        std::vector<std::vector<char>> v(numRows, std::vector<char>());
        for (int i = 0; i < s.size(); i++) {
            int j = i % ((numRows - 1) * 2);
            std::cout << j << std::endl;

            if (j < numRows) {
                v[j].push_back(s[i]);
            } else {
                v[numRows - (j - numRows + 2)].push_back(s[i]);
            }
        }
        print_2dvector(v);
        std::string ret = "";
        for (auto &i : v) {
            for(auto &j:i) {
                ret += j;
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    std::cout << s.convert("A", 1) << std::endl;
}
