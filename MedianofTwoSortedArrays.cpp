/*******************************************************
 *  MedianofTwoSortedArrays
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/7/23.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/

//4
#include <assert.h>
#include <algorithm>
#include "math.h"
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    return 2.0;
  }
};

void TEST(){
  Solution s;
  vector<int> v1 = {1,3};
  vector<int> v2 = {2};
  vector<int> v3 = {1,2};
  vector<int> v4 = {3,4};
  assert(s.findMedianSortedArrays(v1,v2) == 2.0);
  assert(s.findMedianSortedArrays(v3,v4) == 2.5);

}

int main()
{
  TEST();
}


