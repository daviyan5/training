/*
Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "zxyzxyz"

Output: 3

Explanation: The string "xyz" is the longest without duplicate characters.

Example 2:

Input: s = "xxxx"

Output: 1

Constraints:

    0 <= s.length <= 1000
    s may consist of printable ASCII characters.

*/
#include <string>
#include <bitset>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string &s) {
            int answer = 0;
            int start = 0;
            std::bitset<256> seen;
            
            for (size_t i = 0; i < s.size(); ++i) {
                while (seen[s[i]]) {
                    seen[s[start]] = false;
                    start++;
                }
                seen[s[i]] = true;
                answer = std::max(answer, static_cast<int>(i - start + 1));
            }
            
            return answer;
        }
};
    