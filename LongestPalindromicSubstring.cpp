/*******************************************************
 *  LongestPalindromicSubstring
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/7/26.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


//1
class Solution {
public:
  string longestPalindrome(string s) {
    if (s.size() <= 1)
      return s;

    int max_len = -1;
    int max_left = -1;
    int max_rigth = -1;
    for (int i = 0; i < s.size(); ++i) {
      int left = i;
      int right = i;

      while (left >= 1 && s[left - 1] == s[i]) {
        left -= 1;
      }
      while (right < s.size() - 1 && s[right + 1] == s[i]) {
        right += 1;
      }

      while (left > 0 && right < s.size() - 1) {
        if (s[left -1 ] == s[right + 1]) {
          left -= 1;
          right += 1;
        } else {
          break;
        }
      }

      if (max_len < right - left + 1) {
        max_left = left;
        max_rigth = right;
        max_len = right - left + 1;
      }
    }
    return string(s.begin() + max_left, s.begin() + max_rigth + 1);
  }

};


void TEST(){
  Solution s;

  assert(s.longestPalindrome("ccc") == "ccc");
  assert(s.longestPalindrome("aaaa") == "aaaa");
  assert(s.longestPalindrome("cbbd") == "bb");
  assert(s.longestPalindrome("babcd") == "bab");
  assert(s.longestPalindrome("b") == "b");
  assert(s.longestPalindrome("bb") == "bb");

}

int main()
{
  TEST();
}

 

