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
    void helper(TreeNode* root, int low, int high, TreeNode* parent) {
        if(!root) return;
        while(root && root -> val < low) {
            if(root -> right) parent -> left = root -> right;
            else parent -> left = nullptr;
            root = root -> right;
        }

        while(root && root -> val > high) {
            if(root -> left) parent -> right = root -> left;
            else parent -> right = nullptr;
            root = root -> left;
        }

        if(root) helper(root -> left, low, high, root);
        if(root) helper(root -> right, low, high, root);

        // while(root -> left && root -> left -> val < low) {
        //     if(root -> left -> right) {
        //         root -> left = root -> left -> right;
        //     }
        //     else{
        //         root -> left = nullptr;
        //     }
        // }

        // while(root -> right && root -> right -> val > high) {
        //     if(root -> right -> left) {
        //         root -> right = root -> right -> left;
        //     }
        //     else{
        //         root -> right = nullptr;
        //     }
        // }

        // if(root -> left) helper(root -> left, low, high);
        // if(root -> right) helper(root -> right, low, high);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while(root -> val < low || root -> val > high) {
            while(root && root -> val < low) {
                // cout<<root -> val<<" ";
                if(root -> right) {
                    root = root -> right;
                }
                else{
                    return nullptr;
                }
            }

            while(root && root -> val > high) {
                if(root -> left) {
                    root = root -> left;
                }
                else{
                    return nullptr;
                }
            }
        }
        
        

        if(!root) return nullptr;


        helper(root -> left, low, high, root);
        helper(root -> right, low, high, root);
        return root;
    }
};