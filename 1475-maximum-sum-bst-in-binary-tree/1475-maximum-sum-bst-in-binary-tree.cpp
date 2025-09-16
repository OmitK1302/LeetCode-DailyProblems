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
class Tuple{
    public:
    int lMax, rMin, sum;
    bool flag;
    Tuple(int a, int b, int c, bool d){
        lMax = a;
        rMin = b;
        sum = c;
        flag = d;
    }

};
class Solution {
    int ans = 0;

    Tuple* helper(TreeNode* root){
        if(!root) return new Tuple(INT_MIN, INT_MAX, 0, true);

        Tuple* left = helper(root->left);
        Tuple* right = helper(root->right);

        if(left->flag && right->flag && root->val > left->lMax && root->val < right->rMin){
            int currSum = root->val + left->sum + right->sum;
            ans = max(ans, currSum);
            return new Tuple(max(root->val, right->lMax), min(root->val, left->rMin), currSum, true);
        }
        return new Tuple(INT_MIN, INT_MAX, 0, false);
    }

public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};

//Leetcode 1373