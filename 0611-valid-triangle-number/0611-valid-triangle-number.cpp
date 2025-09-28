class Solution {
    // bool check(int a, int b, int c) {
    //     if(a < b+c && b < a+c && c < a+b) return true;
    //     return false;
    // }

    int srch(vector<int>& nums, int l, int r, int val) {
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] <= val) {
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return l-1;
    }

public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        
        if(nums.size() < 3) return 0;
        // return srch(nums, 0, nums.size() - 1, 4);

        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i+1; j < nums.size() - 1; j++) {
                int sum = nums[i] + nums[j];

                int indx = srch(nums, j+1, nums.size() - 1, sum-1);

                if(indx != j || indx != nums.size()) {
                    // cout<<i<<" "<<j<<" "<<indx - j<<endl;
                    // cout<<indx - j<<endl;
                    res += (indx - j);
                }
            }
        }

        return res;

        // for(int i = 0; i < nums.size() - 2; i++) {
        //     int a = nums[i];
        //     int l = i+1;
        //     int r = nums.size() - 1;

        //     while(l < r) {
        //         if(check(a, nums[l], nums[r])) {

        //             r--;
        //         }
        //         else{
        //             l++;
        //         }
        //     }
        // }
    }
};