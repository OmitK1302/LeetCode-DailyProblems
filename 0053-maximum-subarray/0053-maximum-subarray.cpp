class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = nums[0];
        // int negRes = 0;
        for(int& num : nums){
            if(sum + num <= 0){
                res = max(res, num);
                sum = 0;
                continue;
            }
            sum += num;
            // if(sum < 0){
            //     negRes = min(abs(negRes), abs(res));
            // }
            res = max(res, sum);
        }
        return res;
    }
};