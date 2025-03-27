class Solution {
public:
    int res = 0;
    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int>temp;
        
        int p1 = l;
        int p2 = mid + 1;
        int currVal = 0;

        // while()

        int next = mid + 1;
        for(int i = l; i <= mid; i++){

            while(next <= r) {
                long long val = 2L*nums[next];
                if(nums[i] > val) {
                    currVal++;
                    next++;
                } 
                else{
                    break;
                }
            }
            res += currVal;


            // for(int j = mid+1; j <= r; j++) {
            //     long long val = 2L*nums[j];
            //     if(nums[i] > val) res++;
            //     else{
            //         break;
            //     }
            // }
        }

        int i = l;
        int j = mid + 1;
        while(i <= mid && j <= r) {
            if(nums[i] < nums[j]) {
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i++]);
        }

        while(j <= r) {
            temp.push_back(nums[j++]);
        }

        int curr = 0;
        for(int k = l; k <= r; k++){
            nums[k] = temp[curr++];
        }
    }
    void mergeSort(vector<int>& nums, int l, int r) {  
        if(l >= r) return;      
        int  mid = (l + r) / 2;
        
        // if(l != r) {
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        // }

        merge(nums, l, mid, r);

    }
    int reversePairs(vector<int>& nums) {
        int l = 0;
        int r = nums.size();

        mergeSort(nums, l, r - 1);

        for(int& num : nums){
            cout<<num<<", ";
        }
        return res;
    }
};