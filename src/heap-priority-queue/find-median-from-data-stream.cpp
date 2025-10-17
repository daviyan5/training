/*
Find Median From Data Stream

The median is the middle value in a sorted list of integers. For lists of even length, there is no
middle value, so the median is the mean of the two middle values.

For example:

    For arr = [1,2,3], the median is 2.
    For arr = [1,2], the median is (1 + 2) / 2 = 1.5

Implement the MedianFinder class:

    MedianFinder() initializes the MedianFinder object.
    void addNum(int num) adds the integer num from the data stream to the data structure.
    double findMedian() returns the median of all elements so far.

Example 1:

Input:
["MedianFinder", "addNum", "1", "findMedian", "addNum", "3" "findMedian", "addNum", "2",
"findMedian"]

Output:
[null, null, 1.0, null, 2.0, null, 2.0]

Explanation:
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.findMedian(); // return 1.0
medianFinder.addNum(3);    // arr = [1, 3]
medianFinder.findMedian(); // return 2.0
medianFinder.addNum(2);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

Constraints:

    -100,000 <= num <= 100,000
    findMedian will only be called after adding at least one integer to the data structure.


*/

#include <functional>
#include <queue>
#include <vector>

class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        if (max_heap.size() > min_heap.size() + 1) {
            int top = max_heap.top();
            max_heap.pop();
            min_heap.push(top);
        } else if (min_heap.size() > max_heap.size()) {
            int top = min_heap.top();
            min_heap.pop();
            max_heap.push(top);
        }
    }

    double findMedian() {
        if ((min_heap.size() + max_heap.size()) % 2 == 0) {
            return static_cast<double>(min_heap.top() + max_heap.top()) / 2.0;
        } else {
            return max_heap.top();
        }
    }

private:
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
};