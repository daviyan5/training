/*
Valid Parentheses

You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

    Every open bracket is closed by the same type of close bracket.
    Open brackets are closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Return true if s is a valid string, and false otherwise.

Example 1:

Input: s = "[]"

Output: true

Example 2:

Input: s = "([{}])"

Output: true

Example 3:

Input: s = "[(])"

Output: false

Explanation: The brackets are not closed in the correct order.

Constraints:

    1 <= s.length <= 1000

*/

#include <string>
#include <stack>

class Solution {
    public:
        bool isValid(std::string s) {
            std::stack<char> st;
            
            auto is_closing = [](const char c) {
                return c == ')' || c == ']' || c == '}';
            };

            auto is_opening = [] (const char o, const char c) {
                return c == ')' ? o == '(' : c == ']' ? o == '[' : c == '}' ? o == '{' : false;
            };

            for (const char &c : s) {
                if (is_closing(c) && (st.empty() || !is_opening(st.top(), c))) {
                    return false;
                } else if (is_closing(c)) {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
            return st.empty();
        }
};    