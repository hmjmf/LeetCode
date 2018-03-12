/*******************************************************
 *  Two_Sum
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

using namespace std;



class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (auto i = nums.begin(); i != nums.end() - 1; i++) {
      auto index = find(i + 1, nums.end(), target - *i);
      if (index != nums.end())
        return {int(i - nums.begin()), int(index - nums.begin())};
    }
  }

};

bool same_vector(const vector<int>& v1, const vector<int>& v2){
  if (v1.size() != v2.size()) return false;
  for(auto i = v1.begin(); i!= v1.end(); i++){
    if(find(v2.begin(),v2.end(),*i) == v2.end()) return false;
  }
  return true;
}
void TEST_Two_Sum(){
  Solution s;

  vector<int> v1 = {2, 7, 11, 15};
  assert(same_vector(s.twoSum(v1, 9),{0,1}));

}

int main()
{
  TEST_Two_Sum();
}
