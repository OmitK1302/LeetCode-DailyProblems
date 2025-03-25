class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int k = nums1.size() - 1;
        int j = n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i--];
            }
            else{
                nums1[k] = nums2[j--];
            }
            k--;
        }

        while(i >= 0){
            nums1[k--] = nums1[i--];
        }

        while(j >= 0){
            nums1[k--] = nums2[j--];
        }



        // vector<int>nums;
        // int k = nums1.size();
        // for(int i = 0; i < nums1.size(); i++){
        //     if(nums1[i] == 0){
        //         k = i;
        //         break;
        //     }
        // }
        
        // int i = 0, j = 0;
        // while(i < k && j < nums2.size()){
        //     if(nums1[i] < nums2[j]){
        //         nums.push_back(nums1[i++]);
        //     }
        //     else {
        //         nums.push_back(nums2[j++]);
        //     }
        // }

        // while(i < k){
        //     nums.push_back(nums1[i++]);
        // }

        // while(j < nums2.size()){
        //     nums.push_back(nums2[j++]);
        // }

        // nums1 = nums;
        // nums1 = {k}; 
    }
};