
#include <vector>
#include <assert.h>
#include "helper.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_l = std::min(1, int(s.size()));
        auto begin = s.begin();
        auto end = begin + 1;
        while (end < s.end()) {
            auto index = std::find(begin, end, *end);
            if (index != end) {
                begin = index + 1;
            }
            end++;
            max_l = std::max(max_l, int(end - begin));
        }
        return max_l;
    }
};

int main()
{
    Solution s;
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("pwwkew") << std::endl;
    
}
