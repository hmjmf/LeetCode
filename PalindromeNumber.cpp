/*******************************************************
 *  PalindromeNumber
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
  bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;

    long int reverse = 0;
    int x_copy = x;
    while (x > 0) {
      reverse *= 10;
      reverse += x % 10;
      x /= 10;
    }
    return x_copy == reverse;
  }

};

void TEST(){
  Solution s;
  assert(s.isPalindrome(121));
  assert(!s.isPalindrome(-121));
  assert(!s.isPalindrome(10));
}

int main()
{
  TEST();
}



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

