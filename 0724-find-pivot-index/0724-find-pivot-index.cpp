class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int& num : nums) {
            sum += num;
        }

        int currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            cout<<currSum<<" "<<sum<<" "<<nums[i]<<endl;
            if(currSum == sum - currSum - nums[i]) return i;
            currSum += nums[i];
        }

        return -1;
    }
};