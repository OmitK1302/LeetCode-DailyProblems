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
    TreeNode* addVal(int node, TreeNode* root) {
        if(root -> val > node) {
            root -> left = (root -> left) ? addVal(node, root -> left) : new TreeNode(node);
            // if(root -> left) {
            //     root -> left = addVal(node, root -> left);
            // }
            // else{
            //     root -> left = new TreeNode(node);
            // }
        }
        else{
            root -> right = (root -> right) ? addVal(node, root -> right) : new TreeNode(node);
            // if(root -> right) {
            //     root -> right = addVal(node, root -> right);
                
            // }
            // else{
            //     root -> right = new TreeNode(node);
            // }
        }

        return root;
    }
    // TreeNode* construct(vector<int>& preorder, int& indx, int l, int r, unordered_map<int, int>& map) {
    //     if(l > r) return nullptr;
    //     TreeNode* root = new TreeNode(preorder[indx++]);
    //     int mid = map[root -> val];
    //     root -> left = construct(preorder, indx, l, mid-1, map);
    //     root -> right = construct(preorder, indx, mid + 1, r, map);

    //     return root;
    // }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // vector<int>inorder = preorder;
        // sort(inorder.begin(), inorder.end());

        // unordered_map<int, int>mp;
        // for(int i = 0; i < inorder.size(); i++) {
        //     mp[inorder[i]] = i;
        // }

        // int indx = 0;
        // return construct(preorder, indx, 0, inorder.size() - 1, mp);

        if(preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++) {
            root = addVal(preorder[i], root);
        }

        return root;
    }
};