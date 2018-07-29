/*******************************************************
 *  ContainerWithMostWater
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/7/29.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

//11
class Solution {
public:
  int maxArea(vector<int>& height) {
    int max_area = 0;
    for (auto i = height.cbegin(); i != height.cend(); ++i) {
      for (auto j = i + 1; j != height.cend(); ++j) {
        max_area = max(int((j - i) * min(*i,*j)), max_area);
      }
    }
    return max_area;
  }
};

void TEST(){
  Solution s;
  vector<int> v = {1,8,6,2,5,4,8,3,7};
  assert(s.maxArea(v) == 49);
}

int main()
{
  TEST();
}


