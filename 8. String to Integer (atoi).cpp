#include <vector>
#include <assert.h>
#include "helper.h"

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
        int ret = 0;
        bool r = false;
        bool is_bgein = false;
        for (auto &i : s) {

            if (i == ' ' or i == '+') {
                if (is_bgein) {
                    break;
                } else {
                    if (i == '+') {
                        is_bgein = true;
                    }
                    continue;
                }
            }

            if (i == '-'){
                if (is_bgein) {
                    break;
                } else {
                    r = true;
                    is_bgein = true;
                    continue;
                }
            }
            if (i < '0' || i > '9') {
                break;
            }
            is_bgein = true;
            if ((INT32_MAX - (i - '0')) / 10 < ret) {
                if (r) {
                    return INT32_MIN;
                } else {
                    return INT32_MAX;
                }
            }
            ret *= 10;
            ret += i - '0';
        }
        if (r) {
            return -ret;
        } else {
            return ret;
        }
    }
};

int main()
{
    Solution s;
    std::cout << s.myAtoi("4") << std::endl;
    std::cout << s.myAtoi("42") << std::endl;
    std::cout << s.myAtoi("-042") << std::endl;
    std::cout << s.myAtoi("+-12") << std::endl;
    std::cout << s.myAtoi("+1") << std::endl;
    std::cout << s.myAtoi("123-") << std::endl;
}
