class Solution {
public:
    // int findPeakElement(vector<int>& nums) {
    //     if(nums.size() == 1) return 0;
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(i == 0) {
    //             if(nums[i+1] < nums[i]) return 0;
    //         }
    //         else if(i == nums.size() - 1 && nums[i] > nums[i-1]) return i; 
    //         else if((nums[i-1] < nums[i]) && (nums[i+1] < nums[i])) return i;
    //     }
    //     return 0;
    // }

    int findPeakElement(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;

        while(l < r) {
            int mid = (l + r) / 2;
            // if((mid + 1 >= nums.size() || nums[mid + 1] < nums[mid]) && (mid - 1 < 0 || nums[mid - 1] < nums[mid])) return mid;
            if(nums[mid] > nums[mid + 1]) {
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }

        return l;
    }
};