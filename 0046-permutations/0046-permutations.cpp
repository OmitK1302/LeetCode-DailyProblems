class Solution {
public:
    void helper(vector<int>& nums, vector<int>& curr, vector<bool>& visited, vector<vector<int>>& res) {
        if(nums.size() == curr.size()) {
            res.push_back(curr);
            return;
        }

        for(int& num : nums) {
            if(!visited[num + 10]) {
                curr.push_back(num);
                visited[num + 10] = true;
                helper(nums, curr, visited, res);
                visited[num + 10] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool>visited(21, false);
        vector<int>curr;
        helper(nums, curr, visited, res);
        return res;
    }
};