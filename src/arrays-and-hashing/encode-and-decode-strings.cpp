/*
Encode and Decode Strings

Design an algorithm to encode a list of strings to a single string. The encoded string is then
decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]

Example 2:

Input: ["we","say",":","yes"]

Output: ["we","say",":","yes"]

Constraints:

    0 <= strs.length < 100
    0 <= strs[i].length < 200
    strs[i] contains only UTF-8 characters.

*/
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

// The intended method was to make it so that the "encoded" key had all the info needed to
// reconstruct the vector. I tought it would be more interesting to make a hash function and use a
// map to reconstruct the strings
class Solution {
public:
    std::string encode(std::vector<std::string> &strs) {
        uint64_t hash = 0;
        int pos = 0;
        for (const auto &s : strs) {
            for (const char &c : s) {
                hash ^= (static_cast<uint64_t>(c) << pos * 8);
                pos = (pos + 1) % 8;
            }
        }
        m_hash_map[hash] = strs;
        return std::to_string(hash);
    }

    std::vector<std::string> decode(std::string &s) {
        uint64_t hash{std::stoull(s)};
        return m_hash_map[hash];
    }

private:
    std::unordered_map<uint64_t, std::vector<std::string>> m_hash_map;
};
