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
    void inOrder(TreeNode* root, vector<int>& res) {
        if(!root) return;

        inOrder(root -> left, res);
        res.push_back(root -> val);
        inOrder(root -> right, res);
    }

    TreeNode* findNode(TreeNode* root, int value) {
        if(!root) return nullptr;

        if(root -> val == value) return root;
        
        TreeNode* l = findNode(root -> left, value);
        TreeNode* r = findNode(root -> right, value);

        if(!l)
            return r;
        return l;

        // return root;
    }

    void recoverTree(TreeNode* root) {
        vector<int>in;
        inOrder(root, in);

        vector<int>vals;
        // if(in[0] > in[1]) {
        //     vals.push_back(in[0]);
        // }
        // if(in[in.size() - 1] < in[in.size() - 2]) {
        //     vals.push_back(in[in.size() - 1]);
        // }
        // for(int i = 1; i < in.size() - 1; i++) {
        //     if(in[i] < in[i-1] && in[i] < in[i+1]) {
        //         vals.push_back(in[i]);
        //     }
        //     if(in[i] > in[i-1] && in[i] > in[i+1]) {
        //         vals.push_back(in[i]);
        //     }
        // }

        vector<int>temp = in;
        sort(temp.begin(), temp.end());
        for(int i = 0; i < in.size(); i++) {
            if(temp[i] != in[i]) {
                vals.push_back(in[i]);
            }
        }
        TreeNode* n1 = findNode(root, vals[0]);
        TreeNode* n2 = findNode(root, vals[1]);

        // n1 -> val;
        // cout<<n2 -> val<<" "<<vals[1];

        // for(int& val : in) {
        //     cout<<val;
        // }


        cout<<vals[1]<<" "<<vals[0];

        // n1 -> val = n2 -> val;

        n1 -> val = vals[1];
        n2 -> val = vals[0];
    }
};