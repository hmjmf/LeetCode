#include <vector>
#include <assert.h>
#include <iostream>
#include <cstdio>
#include "helper.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution s;

    vector<int> v1 = {2, 7, 11, 15};
    print_vector(s.twoSum(v1, 9));


}
