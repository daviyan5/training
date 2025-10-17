/*
Search in Rotated Sorted Array

You are given an array of length n which was originally sorted in ascending order. It has now been
rotated between 1 and n times. For example, the array nums = [1,2,3,4,5,6] might become:

    [3,4,5,6,1,2] if it was rotated 4 times.
    [1,2,3,4,5,6] if it was rotated 6 times.

Given the rotated sorted array nums and an integer target, return the index of target within nums,
or -1 if it is not present.

You may assume all elements in the sorted rotated array nums are unique,

A solution that runs in O(n) time is trivial, can you write an algorithm that runs in O(log n) time?

Example 1:

Input: nums = [3,4,5,6,1,2], target = 1

Output: 4

Example 2:

Input: nums = [3,5,6,0,1,2], target = 4

Output: -1

Constraints:

    1 <= nums.length <= 1000
    -1000 <= nums[i] <= 1000
    -1000 <= target <= 1000


*/
#include <algorithm>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        const size_t n = nums.size();
        size_t left = 0;
        size_t right = n - 1;

        size_t minimum_index = left;
        if (nums[left] < nums[right]) {
            minimum_index = left;
        } else {
            size_t middle;
            while (left < right) {
                middle = (right + left) / 2;
                if (nums[middle] > nums[left]) {
                    left = middle;
                } else {
                    right = middle;
                }
            }
            minimum_index = (middle + 1) % n;
        }
        size_t first = (std::lower_bound(nums.begin(), nums.begin() + minimum_index - 1, target) -
                        nums.begin());
        size_t second =
            (std::lower_bound(nums.begin() + minimum_index, nums.end(), target) - nums.begin());

        return nums[first] == target ? first : nums[second] == target ? second : -1;
    }
};
