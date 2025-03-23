class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i-1] < nums[i]){
                int toSwap = i-1;
                for(int j = i-1; j < nums.size(); j++){
                    if(nums[j] > nums[i-1]){
                        if(nums[toSwap] == nums[i-1]){
                            toSwap = j;
                            continue;
                        }

                        if(nums[j] <= nums[toSwap]){
                            toSwap = j;
                        }
                    }
                }

                int temp = nums[i-1];
                nums[i-1] = nums[toSwap];
                nums[toSwap] = temp;

                int start = i;
                int end = nums.size() - 1;

                while(start < end){
                    int t = nums[start];
                    nums[start] = nums[end];
                    nums[end] = t;

                    start++;
                    end--;
                }

                return;
            }
        }

        reverse(nums.begin(), nums.end());
        return;
    }
};