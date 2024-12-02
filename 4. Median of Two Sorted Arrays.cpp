#include <vector>
#include <assert.h>
#include "helper.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int target = (nums1.size() + nums2.size()) / 2 + 1;
        std::vector<int> max_v = {0, 0};
        int i = 0;
        int i1 = 0;
        int i2 = 0;
        while (i < target)
        {
            if (i1 < nums1.size() and i2 < nums2.size()) {
                if(nums1[i1] < nums2[i2]) {
                    max_v[0] = max_v[1];
                    max_v[1] = nums1[i1];
                    i1 += 1;
                } else {
                    max_v[0] = max_v[1];
                    max_v[1] = nums2[i2];
                    i2 += 1;
                }
            } else if (i1 >= nums1.size()){
                max_v[0] = max_v[1];
                max_v[1] = nums2[i2];
                i2 += 1;
            } else {
                max_v[0] = max_v[1];
                max_v[1] = nums1[i1];
                i1 += 1;
            }
            i += 1;
        }
        
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            return double(max_v[0] + max_v[1]) / 2;
        } else {
            return max_v[1];
        }
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    std::cout << s.findMedianSortedArrays(v1, v2) << std::endl;
    vector<int> v3 = {1, 2};
    vector<int> v4 = {3, 4};
    std::cout << s.findMedianSortedArrays(v3, v4) << std::endl;

    vector<int> v5 = {};
    vector<int> v6 = {1};
    std::cout << s.findMedianSortedArrays(v5, v6) << std::endl;

    vector<int> v7 = {};
    vector<int> v8 = {1,2,3,4};
    std::cout << s.findMedianSortedArrays(v7, v8) << std::endl;

}
