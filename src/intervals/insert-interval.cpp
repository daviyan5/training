/**
Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [start_i, end_i] represents the start and the end time of the ith interval. intervals is initially sorted in ascending order by start_i.

You are given another interval newInterval = [start, end].

Insert newInterval into intervals such that intervals is still sorted in ascending order by start_i and also intervals still does not have any overlapping intervals. You may merge the overlapping intervals if needed.

Return intervals after adding newInterval.

Note: Intervals are non-overlapping if they have no common point. For example, [1,2] and [3,4] are non-overlapping, but [1,2] and [2,3] are overlapping.

Example 1:

Input: intervals = [[1,3],[4,6]], newInterval = [2,5]

Output: [[1,6]]

Example 2:

Input: intervals = [[1,2],[3,5],[9,10]], newInterval = [6,7]

Output: [[1,2],[3,5],[6,7],[9,10]]

Constraints:

    0 <= intervals.length <= 1000
    newInterval.length == intervals[i].length == 2
    0 <= start <= end <= 1000

*/

#include <vector>

class Solution {
public:
    static bool checkOverlap(const std::vector<int> &a, const std::vector<int> &b) {
        return a[0] <= b[1] && a[1] >= b[0];
    }
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> overlaps;
        std::vector<std::vector<int>> answer;
        size_t index = 0;
        for (const auto &interval : intervals) {
            if (checkOverlap(interval, newInterval)) {
                overlaps.push_back(interval);
            } else {
                answer.push_back(interval);
            }
        }
        if (!overlaps.empty()) {
            const int new_a = std::min(newInterval[0], overlaps.front()[0]);
            const int new_b = std::max(newInterval[1], overlaps.back()[1]);
            newInterval = {new_a, new_b};
        }
        auto it = std::lower_bound(answer.begin(), answer.end(), newInterval);
        answer.insert(it, newInterval);
        return answer;
    }
};
