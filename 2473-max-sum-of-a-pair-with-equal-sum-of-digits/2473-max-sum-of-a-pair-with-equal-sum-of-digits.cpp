class Solution {
public:
    int sumOfDigits(int n){
        int sum = 0;
        while(n > 0){
            sum += (n%10);
            n /= 10;
        }

        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int>map;
        int res = -1;
        for(int i = 0; i < nums.size(); i++){
            int curr = sumOfDigits(nums[i]);
            
            if(map.count(curr)){
                res = max(res, map[curr] + nums[i]);
                map[curr] = max(map[curr], nums[i]);
            }
            else{
                map[curr] = nums[i];
            }
        }

        return res;
    }
};