/*
Longest Consecutive Sequence

Given an array of integers nums, return the length of the longest consecutive sequence of elements
that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the
previous element. The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [2,20,4,10,3,4,5]

Output: 4

Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:

Input: nums = [0,3,2,5,4,6,1,1]

Output: 7

Constraints:

    0 <= nums.length <= 1000
    -10^9 <= nums[i] <= 10^9

*/
#include <cstdint>
#include <unordered_map>
#include <vector>

/*
    This solution has a tricky logic. Basically, what we want is to check a map and
    immediately know the length of the largest consecutive sequence that contains that number.
    We then should check the previous and next numbers, and "merge" their sequences.
    The problem is: How can we update all the other "participants" in the sequence without falling
   into a O(n²) situation? The answer is that we don't really need to. Since we want to know the
   largest sequence, we only need to update the extremities of our current sequence, since any
   further contribution to our answer can only come from sequences larger than the current one.
*/

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_map<int, uint32_t> count;
        uint32_t ans = 0;

        for (const int& u : nums) {
            if (count[u] == 0) {
                count[u] = count[u - 1] + count[u + 1] + 1;
                count[u - count[u - 1]] = count[u];
                count[u + count[u + 1]] = count[u];
                ans = std::max(ans, count[u]);
            }
        }
        return static_cast<int>(ans);
    }
};
