class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>freq(nums.size() - 1);
        for(int& num : nums){
            if(freq[num - 1] == 1) return num;
            freq[num - 1] = 1;
        }

        return -1;


        // O(nlongn) solution without extra space;
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i < nums.size() - 1; i++){
        //     if(nums[i] == nums[i+1]){
        //         return nums[i];
        //     }
        // }

        // return -1;
    }
};