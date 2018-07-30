/*******************************************************
 *  LongestCommonPrefix
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/7/30.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

//14
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() < 1) return "";
    string result = "";
    for (int i = 0; i < strs[0].size(); ++i) {
      for (int j = 1; j < strs.size(); ++j) {
        if (strs[j][i] != strs[0][i]) {
          return result;
        }
      }
      result += strs[0][i];
    }
    return result;
  }
};

void TEST(){
  Solution s;
  assert(0 == 0);
}

int main()
{
  TEST();
}