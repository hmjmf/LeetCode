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
    if (nums1.empty() || nums2.empty()){
      const vector<int>& nums = nums1.empty() ? nums2 : nums1;
      if (nums.size() % 2 == 0){
        return (nums[nums.size()/2] + nums[nums.size()/2 - 1]) / 2.0;
      } else {
        return nums[nums.size()/2];
      }
    }

    //numsA is the big one
    const vector<int>& numsA = nums1.size() > nums2.size() ? nums2 : nums1;
    const vector<int>& numsB = nums1.size() > nums2.size() ? nums1 : nums2;

    size_t m = numsA.size();
    size_t n = numsB.size();

    size_t left = 0;
    size_t right = m;
    size_t middleA, middleB;

    while (left <= right){
      middleA = (left + right) / 2;
      middleB = (m + n + 1) / 2 - middleA;

      if (middleA < m && numsB[middleB - 1] > numsA[middleA]){
        left = middleA + 1;
      } else if (middleA >= 1 && numsA[middleA - 1] > numsB[middleB]) {
        right = middleA - 1;
      } else {
        break;
      }
    }

    int left_max, right_min;
    if (middleA == 0) {
      assert(middleB >= 1);
      left_max = numsB[middleB - 1];
    } else if (middleB == 0) {
      assert(middleA >= 1);
      left_max = numsA[middleA - 1];
    } else {
      left_max = max(numsA[middleA - 1] ,numsB[middleB - 1]);
    }

    if ((m + n) % 2 == 1) {
      right_min = left_max;
    } else if (middleA == m){
      assert(middleB < n);
      right_min = numsB[middleB];
    } else if (middleB == n) {
      assert(middleA < m);
      right_min = numsA[middleA];
    } else {
      right_min = min(numsA[middleA] ,numsB[middleB]);
    }
    return (left_max + right_min) / 2.0;
  }
};

void TEST(){
  Solution s;
  vector<int> v1 = {1,3};
  vector<int> v2 = {2};
  vector<int> v3 = {1,2};
  vector<int> v4 = {3,4};
  vector<int> v5 = {1,5,13,17};
  vector<int> v6 = {8,12,19,30,31};
  vector<int> v7 = {3};
  vector<int> v8 = {1,2};
  assert(abs(s.findMedianSortedArrays(v1,v2) - 2.0) < 1e-6);
  assert(abs(s.findMedianSortedArrays(v7,v8) - 2.0) < 1e-6);
  assert(abs(s.findMedianSortedArrays(v5,v6) - 13) < 1e-6);
  assert(abs(s.findMedianSortedArrays(v3,v4) - 2.5) < 1e-6);



}

int main()
{
  TEST();
}


