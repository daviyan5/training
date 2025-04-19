/*
Valid Anagram

Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true

Example 2:

Input: s = "jar", t = "jam"

Output: false
*/
#include <string>
#include <cstdint>

class Solution {
    public:
        bool isAnagram(std::string &s, std::string &t) {
            int frequency[26];
            for (uint8_t i = 0; i < 26; ++i) {
                frequency[i] = 0;
            }
            for (const char &c : s) {
                const uint8_t index = static_cast<uint8_t>(c) - static_cast<uint8_t>('a'); 
                frequency[index] += 1;
            }
            for (const char &c : t) {
                const uint8_t index = static_cast<uint8_t>(c) - static_cast<uint8_t>('a');
                if (frequency[index] == 0) {
                    return false;
                } else {
                    frequency[index] -= 1;
                }
            }
            for (uint8_t i = 0; i < 26; ++i) {
                if (frequency[i] != 0) {
                    return false;
                }
            }
            return true;
        }
};
    