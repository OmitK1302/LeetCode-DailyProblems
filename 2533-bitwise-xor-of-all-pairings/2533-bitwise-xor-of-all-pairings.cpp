class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // If both the size of nums1 and nums2 are even
        if(n1 % 2 == 0 && n2 % 2 == 0){
            return 0;
        }

        // if size of nums2 is even and size of nums1 is odd.
        int ans = 0;
        if(n1 % 2 != 0 && n2 % 2 == 0){
            for(int& num : nums2){
                ans ^= num;
            }
        }

        // if size of nums2 is odd and size of nums1 is even
        else if(n1 % 2 == 0 && n2 % 2 != 0){
            for(int& num : nums1){
                ans ^= num;
            }
        }

        // if both the sizes of nums1 and nums2 are odd
        else if(n1 % 2 != 0 && n2 % 2 != 0){
            for(int& num : nums1){
                ans ^= num;
            }
            for(int& num : nums2){
                ans ^= num;
            }
        }

        return ans;
    }
};