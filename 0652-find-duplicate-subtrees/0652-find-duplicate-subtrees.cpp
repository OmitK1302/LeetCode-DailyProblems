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
    unordered_map<string, bool>mp;
    vector<TreeNode*> res;
    // string helper(TreeNode* root, string& str) {
    //     if(!root) return "";

    //     string temp1 = to_string(root -> val);
    //     temp1 += "_" + helper(root -> left, str) + "_" + helper(root -> right, str);
    //     if(mp.count(temp1)) {
    //         if(mp[temp1]) {
    //             mp[temp1] = false;
    //             res.push_back(root);
    //         }
    //     }
    //     else {
    //         mp[temp1] = true;
    //     }

    //     string temp2 = str;
    //     temp2 += helper(root -> left, str);
    //     if(mp.count(temp2)) {
    //         if(mp[temp2]) {
    //             mp[temp2] = false;
    //             res.push_back(root);
    //         }
    //     }
    //     else {
    //         mp[temp2] = true;
    //     }

    //     return {temp1, temp2}
    // }
    string helper(TreeNode* root) {
        if(!root) return "";

        string temp1 = to_string(root -> val);
        temp1 += ("_" + helper(root -> left) + "_" + helper(root -> right));
        if(mp.count(temp1)) {
            if(mp[temp1]) {
                mp[temp1] = false;
                res.push_back(root);
            }
        }
        else {
            mp[temp1] = true;
        }

        // string temp2 = str;
        // temp2 += helper(root -> left, str);
        // if(mp.count(temp2)) {
        //     if(mp[temp2]) {
        //         mp[temp2] = false;
        //         res.push_back(root);
        //     }
        // }
        // else {
        //     mp[temp2] = true;
        // }

        // return {temp1, temp2}

        return temp1;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return res;
    }
};