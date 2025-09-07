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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);

        int res = 0;
        while(!que.empty()) {
            int n = que.size();
            res = 0;
            for(int i = 0; i < n; i++) {
                TreeNode* curr = que.front();
                // cout<<curr -> val;
                que.pop();
                res += curr -> val;

                if(curr -> left) que.push(curr -> left);
                if(curr -> right) que.push(curr -> right);
            }
            // cout<<endl;
        }

        return res;
    }
};