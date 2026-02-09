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
    TreeNode* constBST(vector<int>& arr, int lb, int rb) {
        if(lb > rb) return nullptr;

        int mid = (lb + rb) / 2;
        TreeNode* newNode = new TreeNode(arr[mid]);
        newNode -> left = constBST(arr, lb, mid - 1);
        newNode -> right = constBST(arr, mid + 1, rb);

        return newNode;
    }
    void traverse(TreeNode* root, vector<int>& arr) {
        if(!root) return;

        traverse(root -> left, arr);
        arr.push_back(root -> val);
        traverse(root -> right, arr);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        traverse(root, arr);

        return constBST(arr, 0, arr.size() - 1);
    }
};