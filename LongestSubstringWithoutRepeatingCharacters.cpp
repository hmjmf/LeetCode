/*******************************************************
 *  LongestSubstringWithoutRepeatingCharacters
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/7/23.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/

//3
#include <assert.h>
#include <algorithm>
#include "math.h"
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() <=0 ) return 0;
    auto window_begin = s.cbegin();
    auto window_end = window_begin + 1;
    int max_len = 1;
    while (window_end != s.cend()){
      auto index = find(window_begin,window_end,*window_end);
      if (index != window_end) {
        window_begin = index + 1;
      }
      window_end++;
      max_len = max_len > window_end-window_begin ? max_len:window_end-window_begin;
    }
    return max_len;
  }
};

void TEST(){
  Solution s;
  assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
  assert(s.lengthOfLongestSubstring("bbbbb") == 1);
  assert(s.lengthOfLongestSubstring("pwwkew") == 3);
}

int main()
{
  TEST();
}
