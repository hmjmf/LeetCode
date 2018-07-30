/*******************************************************
 *  RomantoInteger
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/7/29.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <unordered_map>

using namespace std;


//6
class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char,int> value = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };

    int result = value[s[s.size() - 1]];

    for (int i = s.size() - 2; i >= 0; --i) {
      if (value[s[i]] < value[s[i + 1]]) {
        result -= value[s[i]];
      } else {
        result += value[s[i]];
      }
    }
    return result;
  }

};

void TEST(){
  Solution s;
  assert(s.romanToInt("III") == 3 );
  assert(s.romanToInt("IV") == 4 );
  assert(s.romanToInt("IX") == 9 );
  assert(s.romanToInt("LVIII") == 58 );
  assert(s.romanToInt("MCMXCIV") == 1994 );
}

int main()
{
  TEST();
}

