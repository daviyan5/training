/*
Implement Trie (Prefix Tree)

A prefix tree (also known as a trie) is a tree data structure used to efficiently store and retrieve keys in a set of strings. Some applications of this data structure include auto-complete and spell checker systems.

Implement the PrefixTree class:

    PrefixTree() Initializes the prefix tree object.
    void insert(String word) Inserts the string word into the prefix tree.
    boolean search(String word) Returns true if the string word is in the prefix tree (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:

Input: 
["Trie", "insert", "dog", "search", "dog", "search", "do", "startsWith", "do", "insert", "do", "search", "do"]

Output:
[null, null, true, false, true, null, true]

Explanation:
PrefixTree prefixTree = new PrefixTree();
prefixTree.insert("dog");
prefixTree.search("dog");    // return true
prefixTree.search("do");     // return false
prefixTree.startsWith("do"); // return true
prefixTree.insert("do");
prefixTree.search("do");     // return true

Constraints:

    1 <= word.length, prefix.length <= 1000
    word and prefix are made up of lowercase English letters.

*/

#include <string>
#include <memory>


class PrefixTree {
    public:
        PrefixTree() 
        : m_root { std::make_shared<PrefixNode>() } 
        {}
        
        void insert(std::string word) {
            std::shared_ptr<PrefixNode> cur = m_root;
            for (const char &c : word) {
                size_t index = static_cast<size_t>(c - 'a');
                if (!cur->children[index]) {
                    cur->children[index] = std::make_shared<PrefixNode>();
                }
                cur = cur->children[index];
                cur->is_part = true;
            }
            cur->is_end = true;
        }
        
        bool search(std::string word) {
            std::shared_ptr<PrefixNode> cur = m_root;
            for (const char &c : word) {
                size_t index = static_cast<size_t>(c - 'a');
                cur = cur->children[index];
                if (!cur || !cur->is_part) {
                    return false;
                }
            }
            return cur->is_end;
        }
        
        bool startsWith(std::string prefix) {
            std::shared_ptr<PrefixNode> cur = m_root;
            for (const char &c : prefix) {
                size_t index = static_cast<size_t>(c - 'a');
                cur = cur->children[index];
                if (!cur || !cur->is_part) {
                    return false;
                }
            }
            return true;
        }
    private:
        struct PrefixNode {
            bool is_end { false };
            bool is_part { false };
            std::shared_ptr<PrefixNode> children[26];
        };
        std::shared_ptr<PrefixNode> m_root;
        
};
    

    