#include <vector>
#include <assert.h>
#include "helper.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool r = false;
        if (x == INT32_MIN) {
            return 0;
        }
        if (x < 0) {
            x = -x;
            r = true;
        }
        int ret = 0;
        while (x > 0)
        {
         
            if ((INT32_MAX - (x % 10)) / 10 < ret) {
                return 0;
            }
            ret *= 10;
            ret += (x % 10);
            x /= 10;
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
    std::cout << int(0xFFFFFFFF) << std::endl;
    std::cout << INT32_MAX << std::endl;
    std::cout << INT32_MIN << std::endl;

    // std::cout << s.reverse(123) << std::endl;
    // std::cout << s.reverse(120) << std::endl;
    // std::cout << s.reverse(-123) << std::endl;
    // std::cout << s.reverse(-120) << std::endl;
    // std::cout << s.reverse(1534236469) << std::endl;
    // std::cout << s.reverse(-2147483648) << std::endl;

}
