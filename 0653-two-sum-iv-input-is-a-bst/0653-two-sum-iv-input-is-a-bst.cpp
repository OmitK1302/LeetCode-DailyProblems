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
    void inorder(TreeNode* root, unordered_map<int, bool>& mp) {
        if(!root) return;
        mp[root -> val] = true;
        inorder(root -> left, mp);
        inorder(root -> right, mp);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, bool>mp;
        inorder(root, mp);

        for(auto& it : mp) {
            if(mp.count(k - it.first) && 2*it.first != k) return true;
        }
        return false;
    }
};