/*******************************************************
 *  ReverseInteger
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


//7
class Solution {
public:
  int reverse(int x) {
    int sign = x >= 0 ? 1 : -1;
    x = abs(x);
    long int result = 0;

    while (x > 0){
      result *= 10;
      result += x % 10;
      if (result > INT_MAX){
        return 0;
      }
      x /= 10;
    }

    return result * sign;
  }

};


void TEST(){
  Solution s;

  assert(s.reverse(123) == 321);
  assert(s.reverse(-123) == -321);
  assert(s.reverse(120) == 21);
  assert(s.reverse(1534236469) == 0);


}

int main()
{
  TEST();
}





