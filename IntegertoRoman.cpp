/*******************************************************
 *  IntegertoRoman
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

using namespace std;

//6
class Solution {
public:
  string intToRoman(int num) {
    string roman = "IVXLCDM"; //1 5 10 50 100 500 1000
    string result = "";

    for (int index = 1; index <= (roman.size() - 1) / 2 && num > 0; ++index, num /= 10){
      char ten = roman[index * 2];
      char five = roman[index * 2 - 1];
      char one = roman[index * 2 - 2];

      int number = num % 10;
      if (number <= 3) {
        result = string(number,one) + result;
      } else if (number <= 5) {
        result = string(5 - number,one) + five + result;
      } else if (number <= 8) {
        result = string(1,five) + string(number - 5,one) + result;
      } else {
        result = string(number - 8,one) + ten + result;
      }
    }

    result = string(num,roman[roman.size() - 1]) + result;

    return result;
  }

};

void TEST(){
  Solution s;
  assert(s.intToRoman(3) == "III");
  assert(s.intToRoman(4) == "IV");
  assert(s.intToRoman(9) == "IX");
  assert(s.intToRoman(58) == "LVIII");
  assert(s.intToRoman(1994) == "MCMXCIV");

}

int main()
{
  TEST();
}