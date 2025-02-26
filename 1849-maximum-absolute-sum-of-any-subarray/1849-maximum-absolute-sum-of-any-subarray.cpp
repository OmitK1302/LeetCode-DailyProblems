class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res = 0;
        int currSum = 0;
        int prefixMin = 0;
        int prefixMax = 0;

        for(int& num : nums){
            currSum += num;
            int currMin = abs(currSum - prefixMin);
            int currMax = abs(currSum - prefixMax);

            res = max(res, max(currMin, currMax));
            prefixMin = min(prefixMin, currSum);
            prefixMax = max(prefixMax, currSum);
        }  

        return res;
    }
};