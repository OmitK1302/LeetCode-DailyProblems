/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool helper(TreeNode* root) {
        if(!root) return false;
        if(root -> left == nullptr && root -> right == nullptr) {
            if(root -> val == 1) return true;
            return false;
        }

        bool lft = helper(root -> left);
        bool rt = helper(root -> right);

        if(!lft) {
            root -> left = nullptr;
        }
        if(!rt) {
            root -> right = nullptr;
        }

        return lft || rt || (root -> val == 1);
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
        if((!root) || (root -> left == nullptr && root -> right == nullptr && root -> val != 1)) return nullptr;
        return root;
    }
};