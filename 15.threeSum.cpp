#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "helper.h"

class Solution {
    public:
     std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
       std::sort(nums.begin(), nums.end());
       std::vector<std::vector<int>> result;

        print_vector(nums); // -10 -5 -5 -4 -4 -3 -2 -2 0 0 1 2 2 2 2 5 5
       for (int i = 0; i < nums.size() - 2; i++) {
        if (i >= 1 && nums[i] == nums[i - 1]) {
           continue;
        }
        for (auto v : twoSum(nums, i + 1, -nums[i])) {
           auto r = v;
           r.push_back(nums[i]);
           std::sort(r.begin(), r.end());
           result.push_back(r);
         }
       }
       return result;
    }


    std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int begin, int target) {
      std::vector<std::vector<int>> result;
      int left = begin;
      int right = nums.size() - 1;
      while (left < right) {
        // std::cout << target << " " << left << " " << right << " " << nums[left] << " " <<  nums[right] << std::endl;
        if (nums[left] + nums[right] == target) {
            result.push_back({nums[left], nums[right]});
            left++;
            while (left < right && nums[left] == nums[left-1]) {
                left++;
              }
            right--;
        } else if (nums[left] + nums[right] < target) {
          left++;
          while (left < right && nums[left] == nums[left-1]) {
            left++;
          }
        } else {
            right--;
        }
      }
      return result;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    print_2dvector(s.threeSum(v));

    Clear(__FILE__);
}

  