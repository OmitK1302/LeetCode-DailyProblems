class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < 32; i++){
            int count0 = 0;
            int count1 = 0;
            int temp = (1 << i);
            for(int& num : nums){
                if((num & temp) != 0) count1++;
                else count0++;
            }

            if(count1 % 3 == 1){
                result |= temp;
            }
        }

        return result;
    }
};