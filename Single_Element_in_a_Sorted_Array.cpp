/*******************************************************
 *  Single_Element_in_a_Sorted_Array
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/13.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include <iostream>
#include <vector>
#include <assert.h>
#include <numeric>

using namespace std;

//540
class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size();
    int middle = 0;

    while (left < right){
      middle = left + (right - left) / 2;
      if (nums[middle] != nums[middle+1] && nums[middle] != nums[middle-1])
        return nums[middle];

      if (middle % 2 == 0){
        if (nums[middle] == nums[middle+1]){
          left = middle;
        } else {
          right = middle;
        };
      } else {
        if (nums[middle] == nums[middle-1]){
          left = middle;
        } else {
          right = middle;
        };
      }

    }
    return nums[middle];

  }


};

void TEST_Single_Element_in_a_Sorted_Array(){
  Solution s;

  vector<int> v1 = {1,1,2,3,3,4,4,8,8};
  assert(s.singleNonDuplicate(v1) == 2);

  vector<int> v2 = {3,3,7,7,10,11,11};
  assert(s.singleNonDuplicate(v2) == 10);

  vector<int> v3 = {0,1,1,3,3,4,4,8,8};
  assert(s.singleNonDuplicate(v3) == 0);

  vector<int> v4 = {1,1,3,3,4,4,8,8,5};
  assert(s.singleNonDuplicate(v4) == 5);

  vector<int> v5 = {1,1,2};
  assert(s.singleNonDuplicate(v5) == 2);

  vector<int> v6 = {1,2,2};
  assert(s.singleNonDuplicate(v6) == 1);
}

int main()
{
  TEST_Single_Element_in_a_Sorted_Array();
}
