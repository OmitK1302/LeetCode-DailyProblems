class Solution {
public:
    vector<vector<int>>result;
    void helper(int k, int n, vector<int>& res, vector<bool>& visited, int prev) {
        if(n == 0 && k == 0) {
            result.push_back(res);
            return;
        }
        if(n < 0 || k == 0) return;

        for(int i = prev; i <= 9; i++) {
            if(!visited[i]) {
                res.push_back(i);
                visited[i] = true;
                helper(k-1, n-i, res, visited, i);
                res.pop_back();
                visited[i] = false;
            }
        }

        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>res;
        vector<bool>visited(10, false);
        helper(k, n, res, visited, 1);
        return result;
    }
};