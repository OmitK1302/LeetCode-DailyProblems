/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int>numOfNodes(ListNode* root) {
        vector<int>res;
        ListNode* temp = root;
        while(temp) {
            res.push_back(temp -> val);
            temp = temp -> next;
        }
        return res;
    }
    
    TreeNode* findRes(vector<int>& nodes, int l, int r) {
        if(l > r) {
            return nullptr;
        }
        
        int n = nodes.size();
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root -> left = findRes(nodes, l, mid - 1);
        root -> right = findRes(nodes, mid + 1, r);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode *head) {
        // code here
        vector<int>nodes = numOfNodes(head);
        
        int n = nodes.size();
        
        return findRes(nodes, 0, n-1);
        
        
    }
};