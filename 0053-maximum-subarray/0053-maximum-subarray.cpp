class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;
        for(int& num : nums){
            sum += num;
            res = max(res, sum);

            if(sum < 0){
                sum = 0;
                // continue;
            }
        }

        return res;
    }
};