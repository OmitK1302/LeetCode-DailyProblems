class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // vector<int>pos;
        // vector<int>neg;

        // for(int& num : nums) {
        //     if(num > 0) {
        //         pos.push_back(num);
        //     }
        //     else{
        //         neg.push_back(num);
        //     }
        // }
        // // return neg;
        // // return pos;

        // int j = 0;
        // for(int i = 0; i < nums.size(); i+=2) {
        //     nums[i] = pos[j];
        //     nums[i+1] = neg[j];
        //     j++;
        // }
        // return nums;


        int posIn = 0;
        int negIn = 1;

        vector<int>res(nums.size());

        for(int& num : nums) {
            if(num > 0) {
                res[posIn] = num;
                posIn += 2;
            }
            else{
                res[negIn] = num;
                negIn += 2;
            }
        }
        return res;
    }
};