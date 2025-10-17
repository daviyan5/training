/*
Valid Palindrome

Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and
ignores all non-alphanumeric characters.

Example 1:

Input: s = "Was it a car or a cat I saw?"

Output: true

Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which
is a palindrome.

Example 2:

Input: s = "tab a cat"

Output: false

Explanation: "tabacat" is not a palindrome.

Constraints:

    1 <= s.length <= 1000
    s is made up of only printable ASCII characters.


*/

#include <string>

class Solution {
public:
    bool isPalindrome(std::string &s) {
        size_t start = 0, end = s.length() - 1;
        const auto isalphanumeric{
            [](const char &c) { return isalpha(c) || (c >= '0' && c <= '9'); }};
        while (start < end) {
            while (!isalphanumeric(s[start])) {
                start += 1;
            }
            while (!isalphanumeric(s[end])) {
                end -= 1;
            }
            if (start >= s.length() || end < 0) {
                break;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start += 1;
            end -= 1;
        }
        return true;
    }
};
