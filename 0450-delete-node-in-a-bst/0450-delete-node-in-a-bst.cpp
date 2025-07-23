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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(root -> val == key) {
            if(root -> left == nullptr && root -> right == nullptr) {
                root = nullptr;
                return root;
            }
            else if(root -> left == nullptr) {
                root = root -> right;
                return root;
            }
            else if(root -> right == nullptr){
                root = root -> left;
                return root;
            }
            else {
                TreeNode* temp = root -> right;
                TreeNode* temp1 = root;
                bool moved = false;
                while(temp -> left) {
                    moved = true;
                    temp1 = temp;
                    temp = temp -> left;
                } 

                root -> val = temp -> val;
                if(!moved) {
                    temp1 -> right = temp -> right;
                    return root;
                }
                else{
                    temp1 -> left = temp -> right;
                    // root -> right = temp1 -> right;
                }

                return root;
            }
        }

        if(key > root -> val) {
            root -> right = deleteNode(root -> right, key);
        }

        else {
            root -> left = deleteNode(root -> left, key);
        }

        return root;
    }
};