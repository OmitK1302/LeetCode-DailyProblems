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
    // TreeNode* helper(TreeNode* root, TreeNode* rest) {
    //     if(!root) {
    //         return rest;
    //     }

    //     root -> right = helper(root -> left, helper(root -> right, rest));
    //     returnÂ root;

    // }
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        // root = helper(root, nullptr);

        if(!root) return;
        flatten(root -> right);
        flatten(root -> left);
        root -> right = prev;
        root -> left = nullptr;
        prev = root;


    }
};