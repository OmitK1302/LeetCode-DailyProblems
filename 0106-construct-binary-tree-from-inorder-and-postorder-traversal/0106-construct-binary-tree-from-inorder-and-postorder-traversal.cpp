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
    TreeNode* construct(vector<int>& postrder, unordered_map<int, int>&ind, int& indx, int start, int end) {
        if(start > end) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postrder[indx--]);
        int mid = ind[root -> val];

        root -> right = construct(postrder, ind, indx, mid + 1, end);
        root -> left = construct(postrder, ind, indx, start, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int>ind;
        for(int i = 0; i < inorder.size(); i++) {
            ind[inorder[i]] = i;
        }
        int n = postorder.size();
        int indx = n-1;
        TreeNode* ans = construct(postorder, ind, indx, 0, n-1); 

        return ans;
    }
};