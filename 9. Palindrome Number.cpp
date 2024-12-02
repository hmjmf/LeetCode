#include <vector>
#include <assert.h>
#include "helper.h"
#include "math.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int n = 0;
        int x_n = x;
        while (x_n != 0) {
            x_n /= 10;
            n += 1;
        }
        
        for (int i = 0; i < n / 2; i++) {
            int h = int(x / (pow(10, n - i - 1))) % 10;
            int l = x % int(pow(10, i + 1)) / std::max<int>(1, pow(10, i));
            if (h != l) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    // std::cout << s.isPalindrome(121) << std::endl;
    std::cout << s.isPalindrome(1221) << std::endl;
    // std::cout << s.isPalindrome(1231) << std::endl;


}
