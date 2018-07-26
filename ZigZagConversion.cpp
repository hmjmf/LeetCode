/*******************************************************
 *  ZigZagConversion
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


//6
class Solution {
public:
  string convert(string s, int numRows) {
    if (s.size() <= numRows || numRows <= 1)
      return s;
    string result = "";
    size_t size = s.size();
    for (int layer = 0; layer < numRows; ++layer) {
      int index = layer;
      int jump1 = max(0,  2 + 2 * (numRows - layer - 2)) ;
      int jump2 = layer * 2;

      while (index < s.size()){
        result += s[index];
        index += jump1 == 0 ? jump2 : jump1;
        if (index >= s.size()) break;
        result += s[index];
        index += jump2 == 0 ? jump1 : jump2;
      }
    }

    return string(result);
  }

};


void TEST(){
  Solution s;

  assert(s.convert("A", 1).compare("A") == 0);
  assert(s.convert("AB", 1).compare("AB") == 0);

  assert(s.convert("ABCD", 3).compare("ABDC") == 0);
  assert(s.convert("PAYPALISHIRING", 3).compare("PAHNAPLSIIGYIR") == 0);
  assert(s.convert("PAYPALISHIRING", 4).compare("PINALSIGYAHRPI") == 0);

}

int main()
{
  TEST();
}



 

