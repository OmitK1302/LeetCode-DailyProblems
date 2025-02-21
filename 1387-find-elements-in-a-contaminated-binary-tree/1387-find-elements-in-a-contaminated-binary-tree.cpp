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
class FindElements {
public:
    unordered_map<int, int>vals;
    FindElements(TreeNode* root) {
        traverse(root, 0);
    }
    
    void traverse(TreeNode* root, int rootVal) {
        root -> val = rootVal;
        vals[rootVal] = 1;
        if(root -> left == nullptr && root -> right == nullptr){
            return;
        }
        if(root -> left != nullptr){
            int tempRootVal = 2 * rootVal + 1;
            traverse(root -> left, tempRootVal);
        }
        if(root -> right != nullptr){
            int tempRootVal = 2 * rootVal + 2;
            traverse(root -> right, tempRootVal);
        }
    }

    bool find(int target) {
        return vals[target] == 1;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */