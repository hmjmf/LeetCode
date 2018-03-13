/*******************************************************
 *  Minimum_Size_Subarray_Sum
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/12.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/

#include <iostream>
#include <vector>
#include <assert.h>
#include <numeric>

using namespace std;

//209
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int min_len = nums.size() + 1;
    auto left = nums.begin();
    auto right = left;
    while (right != nums.end() && right >= left){
      int sum = std::accumulate(left, right+1, 0);
      int len = (right - left) + 1;
      if(sum < s){
        right ++;
      } else if (min_len > len){
          min_len = len;
          left ++;
      } else {
        left ++;
      }
    }
    return min_len == nums.size() + 1? 0:min_len;
  }


};


void TEST_Minimum_Size_Subarray_Sum(){
  Solution s;

  vector<int> v1 = {2,3,1,2,4,3};
  assert(s.minSubArrayLen(7,v1) == 2);
  assert(s.minSubArrayLen(4,v1) == 1);

  vector<int> v2 = {1,1};
  assert(s.minSubArrayLen(3,v2) == 0);

}

int main()
{
  TEST_Minimum_Size_Subarray_Sum();
}
