/*******************************************************
 *  RegularExpressionMatching
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/7/26.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

//10
class Solution {
public:
  bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    bool is_match_first = !s.empty() && (p[0] == s[0] or p[0] == '.');

    if (p.size() >= 2 && p[1] == '*') {
      bool match_zero = isMatch(string(s.begin(), s.end()),
                                string(p.begin() + 2, p.end()));

      bool match_one_or_more = is_match_first &&
                               isMatch(string(s.begin() + 1, s.end()),
                                       string(p.begin(), p.end()));

      return match_zero || match_one_or_more;

    } else  {
      return is_match_first && isMatch(string(s.begin() + 1, s.end()),
                                       string(p.begin() + 1, p.end()));
    }

  }


};

void TEST(){
  Solution s;
  assert(!s.isMatch("abcdefg","abcd"));
  assert(!s.isMatch("abcdefg","a.defg"));
  assert(s.isMatch("abcdefg","abcdefg"));
  assert(s.isMatch("abcdefg","abc.efg"));

  assert(!s.isMatch("aa","a"));
  assert(s.isMatch("aa","a*"));
  assert(s.isMatch("ab",".*"));
  assert(s.isMatch("aab","c*.*b"));
  assert(!s.isMatch("mississippi","mis*is*p*."));
  assert(s.isMatch("missssss","mi.*s"));
  assert(s.isMatch("missssss","mi.*ss"));
  assert(s.isMatch("missssss","mi.*sss"));
  assert(s.isMatch("missssss","mis*s"));
  assert(s.isMatch("missssss","mis*ss"));
  assert(s.isMatch("missssss","mis*sss"));
}

int main()
{
  TEST();
}
