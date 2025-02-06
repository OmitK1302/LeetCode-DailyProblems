class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();

        vector<int>res(2, -1);
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(target <= nums[mid]){
                
                r = mid - 1;
            }
            
            else l = mid + 1;
        }
        if(l < nums.size() && nums[l] == target) res[0] = l;

        l = 0;
        r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(target < nums[mid]){
                
                r = mid - 1;
            }
            
            else l = mid + 1;
        }
        
        if((l-1) < nums.size() && nums[l-1] == target) res[1] = l-1;


        return res;
    }
};