/*
Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]

Example 2:

Input: nums = [7,7], k = 1

Output: [7]

Constraints:

    1 <= nums.length <= 10^4.
    -1000 <= nums[i] <= 1000
    1 <= k <= number of distinct elements in nums.

*/
#include <algorithm>
#include <cstdint>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::unordered_map<int, uint32_t> frequency;
        uint32_t max_frequency = 0;
        for (const int &u : nums) {
            frequency[u] += 1;
            max_frequency = std::max(max_frequency, frequency[u]);
        }
        std::vector<std::vector<int>> buckets(max_frequency, std::vector<int>());
        for (const auto &[val, freq] : frequency) {
            if (freq == 0) {
                continue;
            }
            buckets[freq - 1].push_back(val);
        }
        int next_bucket = 0;
        std::vector<int> ans;

        for (size_t i = buckets.size() - 1; i >= 0; --i) {
            std::vector<int> &bucket{buckets[i]};
            if (bucket.size() > 0) {
                ans.insert(ans.end(), bucket.begin(), bucket.end());
                while (ans.size() > k) {
                    ans.pop_back();
                }
                if (ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
};
