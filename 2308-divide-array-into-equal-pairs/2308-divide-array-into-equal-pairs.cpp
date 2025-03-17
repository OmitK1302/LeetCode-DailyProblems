class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int res = 0;
        for(int& num : nums){
            res ^= num;
        }

        return res == 0;
    }
};