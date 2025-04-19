/*
Contains Duplicate

Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
*/

#include <vector>
#include <unordered_map>
#include <cstdint>

class Solution {
    public:
        bool hasDuplicate(std::vector<int>& nums) {
            std::unordered_map<int, bool> visited;
            for (const auto &u: nums) {
                if (visited.count(u)) {
                    return true;
                } else {
                    visited[u] = 1;
                }
            }
            return false;
        }

};
    