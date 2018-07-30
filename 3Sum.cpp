/*******************************************************
 *  3Sum
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/7/30.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/


#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <unordered_map>

using namespace std;

//15
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if(nums.size() < 3)
      return {};
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i >= 1 && nums[i] <= nums[i - 1]) continue;

      int j = i + 1;
      int k = nums.size() - 1;

      while (j < k) {
        int value = nums[i] + nums[j] + nums[k];
        if (value == 0) {
          result.emplace_back(vector<int>({nums[i], nums[j], nums[k]}));
          j++;
          k--;
          while (j < k && nums[j] == nums[j-1]) j++;
          while (j < k && nums[k] == nums[k+1]) k--;
        } else if (value < 0) {
          j++;
        } else {
          k--;
        }
      }
    }
    return result;
  }

};

void TEST(){
  Solution s;
  assert(0 == 0);
}

int main()
{
  TEST();
}
