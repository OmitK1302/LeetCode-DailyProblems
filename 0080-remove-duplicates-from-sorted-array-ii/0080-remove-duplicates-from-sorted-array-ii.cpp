class Solution {
public:
    int i = 0;
    int j = 1;
    int count = 0;
    int removeDuplicates(vector<int>& nums) {
        while(j < nums.size()){
            if(nums[i] == nums[j]){
                
                if(count == 2){
                    nums.erase(nums.begin() + j);
                    j--;
                }
                count = 2;
            }
            else{
                i = j;
                count = 0;
            }
            j++;
        }
        return nums.size();
    }
};