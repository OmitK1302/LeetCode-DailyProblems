class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int maxReach = 0;
        int i = 0;
        int patch = 0;
        // return 1;
        while(maxReach < n){
            if(i < nums.size() && nums[i] <= maxReach + 1){
                maxReach += nums[i];
                i++;
            }
            else{
                patch++;
                maxReach += (maxReach + 1);
            }
        }
        return patch;
    }
};