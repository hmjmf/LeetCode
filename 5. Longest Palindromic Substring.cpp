#include <vector>
#include <assert.h>
#include "helper.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][i] = 1
        // dp[i-1][j+1] = dp[i][j] && s[i-1] == s[j+1] ? 1 : 0
        // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
            if(i + 1 < s.size()) {
                dp[i][i + 1] = s[i] == s[i+1];
            }
        }

 
        for( int i = s.size() - 2; i >= 0; i--) {
            for (int j = i + 2; j < s.size(); j++) {
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
            }
        }

        // print_2dvector(dp);

        std::string ret = "";
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (dp[i][j] && j - i + 1 > ret.size()){
                    ret = s.substr(i, j - i + 1);
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    // std::cout << s.longestPalindrome("babad") << std::endl;
    // std::cout << s.longestPalindrome("cbbd") << std::endl;
    // std::cout << s.longestPalindrome("a") << std::endl;
    std::cout << s.longestPalindrome("aaaaa") << std::endl;
}
