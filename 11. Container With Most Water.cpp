#include <vector>
#include <assert.h>
#include "helper.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int b = 0;
        int e = height.size() - 1;
        int m = 0;
        while (b < e)
        {
            m = std::max(m, std::min(height[b], height[e]) * (e - b));
            if (height[e] < height[b]) {
                e--;
            }else {
                b++;
            }
        }
        return m;
    }
};

int main()
{
    Solution s;
    std::vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << s.maxArea(v) << std::endl;
}
