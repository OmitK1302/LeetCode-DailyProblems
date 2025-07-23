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
    TreeNode* construct(istringstream& ss) {
        string val;
        ss >> val;
        if(val == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root -> left = construct(ss); 
        root -> right = construct(ss); 

        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "# ";
        return to_string(root -> val) + " " + serialize(root -> left) + serialize(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        cout<<data;
        return construct(ss);
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));




// ------------------------------------------------------------------------------------------------------------------------------------------------

// This method will not work for duplicate node values

/*
class Codec {
    void preNode(TreeNode* root, vector<int>&pre) {
        if(!root) return ;

        pre.push_back(root -> val);
        preNode(root -> left, pre);
        preNode(root -> right, pre);
    }

    void inNode(TreeNode* root, vector<int>&in) {
        if(!root) return ;

        inNode(root -> left, in);
        in.push_back(root -> val);
        inNode(root -> right, in);
    }

    vector<int> order(string data, int start, int end) {
        vector<int>res;
        for(int i = start; i < end; i++) {
            string temp;
            while(i < end && data[i] != ' ') {
                temp += data[i++];
            }
            res.push_back(stoi(temp));
        }
        return res;
    }

    TreeNode* construct(vector<int>& pre, unordered_map<int, int>& mp, int& indx, int start, int end) {
        if(start > end) return nullptr;
        TreeNode* root = new TreeNode(pre[indx++]);
        int mid = mp[root -> val];

        root -> left = construct(pre, mp, indx, start, mid - 1);
        root -> right = construct(pre, mp, indx, mid + 1, end);

        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int>pre;
        vector<int>in;

        preNode(root, pre);
        inNode(root, in);

        string str;
        int n = pre.size();
        for(int& nd : pre) {
            str += to_string(nd) + " ";
        }

        for(int& nd : in) {
            str += to_string(nd) + " ";
        }

        // cout<<str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.length();
        vector<int>pre = order(data, 0, n/2);
        vector<int>in = order(data, n/2, n);

        unordered_map<int, int>mp;
        for(int i = 0; i < in.size(); i++) {
            mp[in[i]] = i;
        }

        for(int& val : pre) {
            cout<<val<<" ";
        }
        cout<<endl;
        
        int indx = 0;
        int len = in.size();
        return construct(pre, mp, indx, 0, len - 1);
        // return nullptr;

    }
};

*/