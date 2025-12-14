#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <iostream>
#include "helper.h"

class Solution {
    public:
     int threeSumClosest(std::vector<int>& nums, int target) {
       std::sort(nums.begin(), nums.end());
       int close_sum = 0;
       int close_diff = INT_MAX;


    //    print_vector(nums); // -10 -5 -5 -4 -4 -3 -2 -2 0 0 1 2 2 2 2 5 5
       for (int i = 0; i < nums.size() - 2; i++) {
        if (i >= 1 && nums[i] == nums[i - 1]) {
           continue;
        }
        int sum = twoSumClosest(nums, i + 1, target - nums[i]);
        if (std::abs(sum + nums[i] - target) < close_diff) {
          close_diff = std::abs(sum + nums[i] - target);
          close_sum = sum + nums[i];
          std::cout << "*" << sum << " " << nums[i] << std::endl;
        }
       }
       return close_sum;
    }


    int twoSumClosest(std::vector<int>& nums, int begin, int target) {
      int left = begin;
      int right = nums.size() - 1;
      int mini_diff = INT_MAX;
      int sum = 0;

      while (left < right) {
        // std::cout << target << " " << left << " " << right << " " << nums[left] << " " <<  nums[right] << std::endl;
        int diff = std::abs(nums[left] + nums[right] - target);
        if (diff < mini_diff) {
          mini_diff = diff;
          sum = nums[left] + nums[right];
        }

        if (nums[left] + nums[right] == target) {
          return target;
        } else if (nums[left] + nums[right] < target) {
          left++;
        } else {
          right--;
        }

      }
    //   std::cout << sum << " " << nums[left] << " " << nums[right] << " " << target << std::endl;

      return sum;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {10,20,30,40,50,60,70,80,90};
    std::cout << s.threeSumClosest(v, 1) << std::endl;

    Clear(__FILE__);
}

  