class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // unordered_map<int, int>map;

        // for(int i = 0; i < nums.size(); i++) {
        //     map[nums[i]] = i;
        // }

        vector<int>res(nums.size());

        int j = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            bool flag = false;
            int val1 = nums[i];
            for(int j = 0; j < nums.size(); j++) {
                int indx = (i + j) % n;
                if(nums[indx] > val1) {
                    res[i] = nums[indx];
                    flag = true;
                    break;
                }
            }    
            if(!flag)
                res[i] = -1;


            
        }

        return res;
    }
};