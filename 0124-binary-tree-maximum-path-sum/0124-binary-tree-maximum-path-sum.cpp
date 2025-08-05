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

    // -------------------METHOD 1---------------------------------------
    int res = INT_MIN;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int leftSum = max(0, dfs(root -> left));
        int rightSum = max(0, dfs(root -> right));
        res = max(res, leftSum + rightSum + root -> val);
        return root -> val + max(leftSum, rightSum);
    }
    // -------------------------------------------------------------------



    //  ----------------METHOD 2-----------------------------------------

    // int totalPaths(TreeNode* root) {
    //     if(!root) return INT_MIN;

    //     if(root -> left == nullptr && root -> right == nullptr) {
    //         return root -> val;
    //     }

    //     int left = totalPaths(root -> left);
    //     int right = totalPaths(root -> right);

    //     long long left1 = left;
    //     long long right1 = right;
    //     long long currRoot = root -> val;

    //     long long val = left1 + right1 + currRoot;

    //     if(val > INT_MIN && val > res) {
    //         res = val;
    //     }

    //     res = max(res, max(left, right));
    //     return max(root -> val, max(left, right) + root -> val);

    // }

    // void dfs(TreeNode* root) {
    //     if(!root) return;

    //     res = max(totalPaths(root), res);

    //     dfs(root -> left);
    //     dfs(root -> right);
    // }
    //  ---------------------------------------------------------------------------------------------------



    int maxPathSum(TreeNode* root) {
        // if(root -> left == nullptr && root -> right == nullptr) return root -> val;

        if(!root) return 0;
        dfs(root);

        return res;
    }
};