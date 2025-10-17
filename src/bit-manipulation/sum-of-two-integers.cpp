/**
Sum of Two Integers

Given two integers a and b, return the sum of the two integers without using the + and - operators.

Example 1:

Input: a = 1, b = 1

Output: 2

Example 2:

Input: a = 4, b = 7

Output: 11

Constraints:

 -1000 <= a, b <= 1000

 */

#include <cstdint>

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
