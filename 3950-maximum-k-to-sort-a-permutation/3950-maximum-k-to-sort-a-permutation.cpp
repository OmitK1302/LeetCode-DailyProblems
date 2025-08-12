class Solution {
public:
    int sortPermutation(vector<int>& nums) {    
        int temp = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i) {
                temp &= nums[i];
            }
        }

        return temp == INT_MAX ? 0 : temp;
    }

    // return 0;
    // int sortPermutation(vector<int>& nums) {

    //     int n = nums.size();
    //     vector<bool>visited(n, false);
    //     int ans = n;
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(visited[i]) continue;
    //         // visited[i] = true;

    //         int currVal = nums[i];
    //         int currAnd = i;
    //         int size = 1;
    //         while(currVal != i) {
    //             visited[currVal] = true;
    //             currAnd &= currVal;
    //             currVal = nums[currVal];
    //             size++;
    //         }

    //         if(size > 1) {
    //             ans = min(ans, currAnd);
    //         }
    //     }

    //     return ans == n ? 0 : ans;
    // }

    
};

