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
// class Solution {
// public:
//     unordered_map<int, TreeNode*>mp;

//     bool validate(TreeNode* root, long long minVal, long long maxVal) {
//         if (root == nullptr) return true;

//         // Check if the current node violates the range
//         if (root->val <= minVal || root->val >= maxVal) return false;

//         // Recursively validate the left and right subtrees
//         return validate(root->left, minVal, root->val) && validate(root->right, root->val, maxVal);
//     }

//     bool isValidBST(TreeNode* root) {
//         // Use long long to avoid overflow issues with INT_MIN and INT_MAX
//         return validate(root, LONG_LONG_MIN, LONG_LONG_MAX);
//     }

//     TreeNode* merge(TreeNode* root1, TreeNode* root2) {
//         if(root2 && root1 && root2 -> left && root2 -> left -> val == root1 -> val) {
//             root2 -> left = root1;
//             if(root2 -> right) {
//                 mp[root2 -> right -> val] = root2;
//             }

//             return root2;
//         }
//         else if(root2 && root1 && root2 -> right && root2 -> right -> val == root1 -> val) {
//             root2 -> right = root1;
//             if(root2 -> left) {
//                 mp[root2 -> left -> val] = root2;
//             }
//             return root2;
//         }

//         if(mp.count(root2 -> val)) {
//             TreeNode* currAnc = mp[root2 -> val];
//             if(currAnc && currAnc -> left && currAnc -> left -> val == root2 -> val) {
//                 currAnc -> left = root2;
//                 mp.erase(root2 -> val);
//                 if(root2 -> left) {
//                     mp[root2 -> left -> val] = root2;
//                 }
//                 if(root2 -> right) {
//                     mp[root2 -> right -> val] = root2;
//                 }
//             }

//             else if(currAnc && currAnc -> right && currAnc -> right -> val == root2 -> val) {
//                 currAnc -> right = root2;
//                 mp.erase(root2 -> val);
//                 if(root2 -> left) {
//                     mp[root2 -> left -> val] = root2;
//                 }
//                 if(root2 -> right) {
//                     mp[root2 -> right -> val] = root2;
//                 }
//             }

//             return root1;
//         }


//         return nullptr;
//     }

//     TreeNode* canMerge(vector<TreeNode*>& trees) {
//         if(trees.size() == 0) return nullptr;
//         if(trees.size() == 1) return trees[0];

//         TreeNode* root1 = trees[0];
//         if(root1 -> left) {
//             mp[root1 -> left -> val] = root1;
//         }
//         if(root1 -> right) {
//             mp[root1 -> right -> val] = root1;
//         }


//         // --------------------------------------------------------------------------------------------------------------------
//         unordered_map<int, TreeNode*>roots;
//         unordered_set<int>children;
//         for(auto&it : trees) {
//             roots[it -> val] = it;
//             if(it -> left) {
//                 children.insert(it -> left -> val);
//             }

//             if(it -> right) {
//                 children.insert(it -> right -> val);
//             }
//         }

//         TreeNode* main = nullptr;
//         for(auto& it : roots) {
//             if(!children.count(it.first)) {
//                 if(main) return nullptr;
//                 main = it.second;
//             }
//         }
//         if(!main) return nullptr;

//         vector<TreeNode*>newTrees;
//         newTrees.push_back(main);
//         int cnt = 0;
//         TreeNode* temp = main;

//         for(auto& it : newTrees) {
//             cout<<it -> val<<" ";
//         }

//         return nullptr;
//         // --------------------------------------------------------------------------------------------------------------------


//         for(int i = 1; i < trees.size(); i++) {
//             TreeNode* root2 = trees[i];
//             root1 = merge(root1, root2);

//             if(!isValidBST(root1)) return nullptr;
//         }
        
//         return root1;
//     }
// };

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
    bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool dfsMerge(TreeNode* node, unordered_map<int, TreeNode*>& roots) {
        if (!node) return true;

        if (!node->left && !node->right && roots.count(node->val)) {
            TreeNode* toMerge = roots[node->val];
            node->left = toMerge->left;
            node->right = toMerge->right;
            roots.erase(node->val); 
        }

        return dfsMerge(node->left, roots) && dfsMerge(node->right, roots);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        if(trees.size() == 1) return trees[0];

        unordered_map<int, TreeNode*> roots;
        unordered_set<int> children;

        for (TreeNode* tree : trees) {
            roots[tree->val] = tree;
            if (tree->left) children.insert(tree->left->val);
            if (tree->right) children.insert(tree->right->val);
        }

        TreeNode* root = nullptr;
        for (TreeNode* tree : trees) {
            if (children.count(tree->val) == 0) {
                if (root) return nullptr; 
                root = tree;
            }
        }

        if (!root) return nullptr; 

        if (!dfsMerge(root, roots)) return nullptr;

        if (roots.size() != 1) return nullptr;

        return isValidBST(root) ? root : nullptr;
    }
};
