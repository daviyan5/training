/*
Products of Array Except Self

Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in O(n) time without using the division operation?

Example 1:

Input: nums = [1,2,4,6]

Output: [48,24,12,8]

Example 2:

Input: nums = [-1,0,1,2,3]

Output: [0,-6,0,0,0]

Constraints:

    2 <= nums.length <= 1000
    -20 <= nums[i] <= 20

*/

#include <vector>

class Solution {
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums) {
            // To solve it without division:
            // ans[i] = pref[i] * suff[i]
            size_t n { nums.size() };
            std::vector<int> pref(n, 1), suff(n, 1);
            for (size_t i = 0; i < n - 1; ++i) {
                pref[i + 1] = nums[i] * pref[i];
            }
            for (size_t i = n - 1; i > 0; --i) {
                suff[i - 1] = nums[i] * suff[i];
            }
            std::vector<int> ans(n, 0);
            for (size_t i = 0; i < n; ++i) {
                ans[i] = pref[i] * suff[i];
            }
            return ans;
        }
};
    