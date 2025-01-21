class Solution {
public:
    // void helper
    vector<vector<int>> subsets(vector<int>& nums) {
        int a = nums.size();
        int n = pow(2, a);
        vector<vector<int>>res;
        for(int i = 0; i < n; i++){
            // int temp = i;
            vector<int>temp;
            for(int j = 0; j < a; j++){
                if(((1 << j) & i) != 0){
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};


// Methond 2
/*
void helper(vector<int>&)
*/