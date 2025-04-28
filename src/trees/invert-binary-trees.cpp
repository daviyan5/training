/*
Invert Binary Tree

You are given the root of a binary tree root. Invert the binary tree and return its root.

Example 1:

Input: root = [1,2,3,4,5,6,7]

Output: [1,3,2,7,6,5,4]

Example 2:

Input: root = [3,2,1]

Output: [3,1,2]

Example 3:

Input: root = []

Output: []

Constraints:

    0 <= The number of nodes in the tree <= 100.
    -100 <= Node.val <= 100

*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if (!root) {
                return nullptr;
            }
            TreeNode *left = invertTree(root->left);
            TreeNode *right = invertTree(root->right);
            root->right = left;
            root->left = right;
            return root;
        }
};