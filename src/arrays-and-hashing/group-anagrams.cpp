/*
Group Anagrams

Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

Example 2:

Input: strs = ["x"]

Output: [["x"]]

Example 3:

Input: strs = [""]

Output: [[""]]

Constraints:

    1 <= strs.length <= 1000.
    0 <= strs[i].length <= 100
    strs[i] is made up of lowercase English letters.

*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
    public:
        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
            std::unordered_map<std::string, std::vector<size_t>> groups_indexes;
            for (size_t i = 0; i < strs.size(); ++i) {
                std::string s { strs[i] };
                std::sort(s.begin(), s.end());
                if (!groups_indexes.count(s)) {
                    groups_indexes[s] = std::vector<size_t>(1, i);
                } else {
                    groups_indexes[s].push_back(i);
                }
            }
            std::vector<std::vector<std::string>> groups;
            for (const auto &[skey, indexes] : groups_indexes) {
                std::vector<std::string> group;
                for (const auto &val : indexes) {
                    group.push_back(strs[val]);
                }
                groups.push_back(group);
            }
            return groups;
        }
    };
    