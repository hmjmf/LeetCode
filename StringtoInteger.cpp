/*******************************************************
 *  StringtoInteger
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
  int myAtoi(string str) {
    long int result = 0;
    int index = 0;
    while (index < str.size() && str[index] == ' ') index += 1;
    if (index >= str.size()) return 0;
    if (str[index] != '-' && str[index] != '+' &&
        (str[index] > '9' || str[index] < '0'))
      return 0;

    int sign = str[index] == '-' ? -1 : 1;
    if(sign == -1 || str[index] == '+') index += 1;
    if (index >= str.size()) return 0;

    while (str[index] >= '0' && str[index] <= '9'){
      result *= 10;
      result += str[index] - '0';
      if (result > INT_MAX){
        return sign == -1 ? INT_MIN : INT_MAX;
      }
      index ++;
    }
    return result * sign;
  }

};


void TEST(){
  Solution s;



  assert(s.myAtoi("42") == 42);
  assert(s.myAtoi("   -42") == -42);
  assert(s.myAtoi("4193 with words") == 4193);
  assert(s.myAtoi("words and 987") == 0);
  assert(s.myAtoi("-91283472332") == -2147483648);
  assert(s.myAtoi("+1") == 1);
}

int main()
{
  TEST();
}





