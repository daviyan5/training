/*
Jump Game

You are given an integer array nums where each element nums[i] indicates your maximum jump length at
that position.

Return true if you can reach the last index starting from index 0, or false otherwise.

Example 1:

Input: nums = [1,2,0,1,0]

Output: true

Explanation: First jump from index 0 to 1, then from index 1 to 3, and lastly from index 3 to 4.

Example 2:

Input: nums = [1,2,1,0,1]

Output: false

Constraints:

    1 <= nums.length <= 1000
    0 <= nums[i] <= 1000


*/
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        size_t maxIndex = 0;
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            maxIndex = std::max(i + static_cast<size_t>(nums[i]), maxIndex);
            if (maxIndex == i) {
                return false;
            }
        }
        return true;
    }
};