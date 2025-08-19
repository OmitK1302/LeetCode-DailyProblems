/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // string res;
    string serialize(TreeNode *root) {
        
        if(root == nullptr) {
            return "null";
        }

        queue<TreeNode*>que;
        que.push(root);

        string res;
        
        while(!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();
            if(curr) {
                res += (to_string(curr -> val) + ",");
                que.push(curr -> left);
                que.push(curr -> right);
            }
            else{
                res += "null,";
            }
        }

        res.pop_back();
        return res;
    }

    TreeNode *deserialize(string res) {
        if(res == "null") return nullptr;
        // cout<<res<<" ";
        stringstream ss(res);
        string token;
        
        getline(ss, token, ',');
        cout<<token<<" "<<endl;
        if(token == "null" || token.empty()) return nullptr;
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*>que;
        que.push(root);
        
        while(!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();
            
            if(!getline(ss, token, ',')) break;
            // cout<<token<<" ";
            if(token != "null" && !token.empty()) {
                curr -> left = new TreeNode(stoi(token));
                que.push(curr -> left);
            }
            
            if(!getline(ss, token, ',')) break;
            // cout<<token<<" ";
            if(token != "null" && !token.empty()) {
                curr -> right = new TreeNode(stoi(token));
                que.push(curr -> right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));