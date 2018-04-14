/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root)
    {
        bool ans = go(root);
        return ans ? root : NULL;
    }
    bool go(TreeNode* node)
    {
        bool left = false;
        bool right = false;
        if (node->left)
            left = go(node->left);
        if (node->right)
            right = go(node->right);
        if (!left) {
            node->left = NULL;
        }
        if (!right) {
            node->right = NULL;
        }
        if (!left && !right && node->val == 0) {
            return false;
        }
        return true;
    }
};
