class Solution {
public:
    bool check(vector<int>& nums) {
        
        // Method 2:
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                count++;
            }
        }

        if(nums[nums.size() - 1] > nums[0]) count++;

        return count <= 1;


        // Method 1:
        // int start = 0;
        // for(int i = 0; i < nums.size() - 1; i++){
        //     if(nums[i] > nums[i + 1]){
        //         start = i + 1;
        //         break;
        //     }
        // }
        // for(int i = start; i < nums.size() - 1; i++){
        //     if(nums[i] > nums[i + 1]) return false;
        // }

        // if(start != 0 && nums[0] < nums[nums.size() - 1]) return false;
        // return true;
    }
};