/*
Container With Most Water

You are given an integer array heights where heights[i] represents the height of the ithith bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Example 1:

Input: height = [1,7,2,5,4,7,3,6]

Output: 36

Example 2:

Input: height = [2,2,2]

Output: 4

Constraints:

    2 <= height.length <= 1000
    0 <= height[i] <= 1000

*/
#include <vector>

class Solution {
    public:
        int maxArea(std::vector<int>& heights) {
            const size_t n = heights.size();
            size_t start = 0;
            size_t end   = n - 1;

            int area = 0;
            while (start < end) {
                int current_area = std::min(heights[start], heights[end]) * (end - start);
                area = std::max(area, current_area);
                
                if (heights[start] < heights[end]) {
                    start++;
                } else {
                    end--;
                }
            }
            return area;
        }
};
    