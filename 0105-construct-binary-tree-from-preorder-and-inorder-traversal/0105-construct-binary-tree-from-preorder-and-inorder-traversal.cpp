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
    TreeNode* helper(vector<int>& preorder, int& indx, unordered_map<int, int>& map, int start, int end) {
        if(start > end) return nullptr;

        TreeNode* root = new TreeNode(preorder[indx++]);

        int mid = map[root -> val];

        root -> left = helper(preorder, indx, map, start, mid - 1);
        root -> right = helper(preorder, indx, map, mid + 1, end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>map;
        int indx = 0;
        for(int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        int n = preorder.size();
        
        return helper(preorder, indx, map, 0, n-1);
    }
};