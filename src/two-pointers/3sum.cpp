/*
3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.

The output should not contain any duplicate triplets. You may return the output and the triplets in any order.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]

Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Example 2:

Input: nums = [0,1,1]

Output: []

Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]

Output: [[0,0,0]]

Explanation: The only possible triplet sums up to 0.

Constraints:

    3 <= nums.length <= 1000
    -10^5 <= nums[i] <= 10^5
*/
#include <algorithm>

#include <vector>

/*
    The intuition behind the two-pointers approach of this problem lies in the fact that,
    supposing a <= b <= c (wlog), given a fixed 'a', we must decrease 'c' by the same amount 
    as we increase b to ensure that a + b + c = 0.
    If we sort the vector, we can iterate over each number 'a' of the now-sorted list, 
    and then look for 'b' and 'c' in the succeeding part of the array (we don't need to 
    check the whole array as it would lead to repeated answers).
    Following the previously mentioned logic, we can use a start pointer to be our 'b' and 
    an end pointer to be our 'c'. We keep increasing start and decreasing end until they cross 
    or the sum is zero. When that happens, we'll have all triples where 'a' is the smallest.
*/
class Solution {
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());

            size_t n = nums.size();
            std::vector<std::vector<int>> triplets;
            for (size_t i = 0; i < n; ++i) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                // No three positives can sum to a 0
                if (nums[i] > 0) {
                    break;
                }
                size_t start = i + 1, end = n - 1;
                while (start < end) {
                    int sum = nums[i] + nums[start] + nums[end];
                    if (sum > 0) {
                        end -= 1;
                    } else if (sum < 0) {
                        start += 1;
                    } else {
                        triplets.push_back({nums[i], nums[start], nums[end]});
                        while (start < end && nums[start] == nums[start + 1]) {
                            start += 1;
                        }
                        while (start < end && nums[end] == nums[end - 1]) {
                            end -= 1;
                        }
                        start += 1;
                        end -= 1;
                    }
                }
            }

            return triplets;
        }
};
    