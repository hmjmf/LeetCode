/*******************************************************
 *  Couples_Holding_Hands
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/12.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
  int minSwapsCouples(vector<int>& row) {
    if(row.size() % 2 != 0) return -1;
    if(row.size() == 0)  return 0;


    int step = 0;
    for(auto i = row.begin(); i!=row.end(); i+=2){
      if(!is_right_partner(*i, *(i+1))){
        auto index = find(i, row.end(), partner_number(*i));
        swap(*(i+1), *(index));
        step += 1;
      }
    }


    return step;
  }
private:
  int partner_number(const int n) const {
    return n%2==0 ? n+1 : n-1;
  }
  bool is_right_partner(const int lh, const int rh) const{
    return partner_number(lh) == rh;
  }


};

void TEST_Couples_Holding_Hands(){
  Solution s;

  vector<int> v1 = {0,1,2,3};
  assert(s.minSwapsCouples(v1) == 0);

  vector<int> v2 = {0, 2, 1, 3};
  assert(s.minSwapsCouples(v2) == 1);

  vector<int> v3 = {3, 2, 0, 1};
  assert(s.minSwapsCouples(v3) == 0);
}

int main()
{
  TEST_Couples_Holding_Hands();
}

