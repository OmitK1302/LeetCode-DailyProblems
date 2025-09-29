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
public:
    int res = 0;
    void helper(TreeNode* root, int maxVal) {
        if(!root) return;

        if(root -> val >= maxVal) res++;
        int currMax = max(maxVal, root -> val);
        helper(root -> left, currMax);
        helper(root -> right, currMax);
    }
    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);
        return res;
    }
};