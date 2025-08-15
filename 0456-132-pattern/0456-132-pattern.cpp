class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // int num1 = -(1e9 + 7);
        // int num2 = -(1e9 + 7);
        // int num3 = -(1e9 + 7);
        

        // for(int i = nums.size() - 1; i >= 0; i--) {
        //     if(nums[i] > num2) {
        //         num3 = num2;
        //         num2 = nums[i];
        //     }

        //     else if(nums[i] < num2) {
        //         if( nums[i] < num3) return true;
        //         if(num3 == -1000000007) {
        //             num2 = nums[i];
        //         }
        //     }
        // }

        // return false;

        int num2 = INT_MIN;
        int n = nums.size();

        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] < num2) return true;

            while(!st.empty() && st.top() < nums[i]) {
                num2 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};