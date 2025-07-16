class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Method 1---------------------------------------------------------------------------
        stack<int> st;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            st.push(nums[i]);
        }

        vector<int> res(n, -1);
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            if(!st.empty()) {
                res[i] = st.top();
            }
            st.push(nums[i]);
        }

        return res;


        // Method 2---------------------------------------------------------------------------
        // vector<int>res(nums.size());
        // int n = nums.size();
        // for(int i = 0; i < n; i++) {
        //     bool flag = false;
        //     int val1 = nums[i];
        //     for(int j = 0; j < nums.size(); j++) {
        //         int indx = (i + j) % n;
        //         if(nums[indx] > val1) {
        //             res[i] = nums[indx];
        //             flag = true;
        //             break;
        //         }
        //     }    
        //     if(!flag)
        //         res[i] = -1;
        // }

        // return res;
    }
};