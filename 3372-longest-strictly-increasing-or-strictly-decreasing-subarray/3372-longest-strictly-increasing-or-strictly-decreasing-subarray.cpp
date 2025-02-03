class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasingLength = 1;
        int decreasingLength = 1;

        int i = 1, j = 0;
        while(i < nums.size()){
            if(nums[i] > nums[i - 1]){
                increasingLength = max(increasingLength, (i - j + 1));
            }
            else{
                j = i;
            }
            i++;
        }

        i = 1;
        j = 0;
        while(i < nums.size()){
            if(nums[i] < nums[i - 1]){
                decreasingLength = max(decreasingLength, (i - j + 1));
            }

            else{
                j = i;
            }

            i++;
        }

        return max(increasingLength, decreasingLength);
    }
};