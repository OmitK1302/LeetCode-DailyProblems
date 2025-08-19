class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                res += i - j + 1;
            }
            else{
                j = i + 1;
            }
        }

        // if(j < nums.size()) {
        //     res += nums.size() - j;
        // }

        return res;
    }
};