class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int& num : nums){
            sum += num;
        }
        int res = 0;
        int currSum = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            currSum += nums[i];
            int rightSum = sum - currSum;

            if((abs(currSum - rightSum)) % 2 == 0){
                res++;
            }
        }

        return res;
    }
};